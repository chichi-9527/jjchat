
#ifndef THREAD_POOL
#define THREAD_POOL


#include <mutex>
#include <queue>
#include <functional>
#include <future>
#include <thread>
#include <utility>
#include <vector>


template <typename T>
class _safe_queue
{
public:
	_safe_queue()
	{

	}
	~_safe_queue()
	{

	}

	//队列是否为空
	bool _empty()
	{
		std::unique_lock<std::mutex> lock(_mutex);
		return _queue.empty();
	}

	int _size()
	{
		std::unique_lock<std::mutex> lock(_mutex);
		return _queue.size();
	}

	// 队列添加元素
	void _emplace(T& t)
	{
		std::unique_lock<std::mutex> lock(_mutex);
		_queue.emplace(t);
	}

	// 队列取出元素
	bool _front(T& t)
	{
		std::unique_lock<std::mutex> lock(_mutex);

		if (_queue.empty())
			return false;
		t = std::move(_queue.front());
		_queue.pop();
		return true;
	}



private:
	std::queue<T> _queue;
	std::mutex _mutex;

};

class _thread_work;

class _thread_pool
{
	friend class _thread_work;

public:
	_thread_pool(int thread_num = 1, int priority_num = 1) :
		_threads(std::vector<std::thread>(thread_num > 1 ? priority_num : 1)),
		_thread_num(thread_num > 1 ? priority_num : 1),
		_queue_num(priority_num > 1 ? priority_num : 1),
		_shutdown(false)
	{

	}

	_thread_pool(const _thread_pool&) = delete;
	_thread_pool(_thread_pool&&) = delete;
	_thread_pool& operator=(const _thread_pool&) = delete;
	_thread_pool& operator=(_thread_pool&&) = delete;


	bool _is_shutdown()
	{
		return _shutdown;
	}

	void start()
	{
		_queues_array.resize(_queue_num);
		for (int i = 0; i < _queue_num; ++i)
		{
			_safe_queue<std::function<void()>>* q = new _safe_queue<std::function<void()>>();
			_queues_array[i] = q;
		}
		_init();
	}

	void shutdown()
	{
		_shutdown = true;
		_conditional_lock.notify_all(); // 通知，唤醒所有工作线程
		for (int i = 0; i < _threads.size(); ++i)
		{
			if (_threads.at(i).joinable()) // 判断线程是否在等待
			{
				_threads.at(i).join(); // 将线程加入到等待队列
			}
		}
		for (auto iter_queue : _queues_array)
		{
			if (iter_queue)
			{
				delete  iter_queue;
				iter_queue = nullptr;
			}
		}
	}

	// Submit a function to be executed asynchronously by the pool
	// 数字越小优先级越高
	template <typename F, typename... Args>
	auto _submit(int priority, F&& f, Args &&...args) -> std::future<decltype(f(args...))>
	{
		// 优先级小于 0 时默认最低优先级
		if ((priority < 0) || (priority > _queue_num - 1))
		{
			priority = _queue_num - 1;
		}

		// Create a function with bounded parameter ready to execute
		std::function<decltype(f(args...))()> func = std::bind(std::forward<F>(f), std::forward<Args>(args)...); // 连接函数和参数定义，特殊函数类型，避免左右值错误
		// Encapsulate it into a shared pointer in order to be able to copy construct
		auto task_ptr = std::make_shared<std::packaged_task<decltype(f(args...))()>>(func);

		auto task_future = task_ptr->get_future();
		// Warp packaged task into void function
		std::function<void()> warpper_func = [task_ptr]()
			{
				(*task_ptr)();
			};
		//_queue._emplace(warpper_func);

		_queues_array.at(priority)->_emplace(warpper_func);
		_conditional_lock.notify_one();
		return task_future;
	}

	// add task func
	// 数字越小优先级越高
	void _post_func(std::function<void()> func, int priority = -1)
	{
		int t_priority = priority;
		// 优先级小于 0 时默认最低优先级
		if ( priority < 0 || priority > _queue_num - 1)
		{
			t_priority = _queue_num - 1;
		}
		_queues_array.at(t_priority)->_emplace(func);
		//_queue._emplace(func);
		_conditional_lock.notify_one();

	}

private:
	void _init();

	//_safe_queue<std::function<void()>> _queue;

	std::vector< _safe_queue<std::function<void()>>* > _queues_array;
	std::vector<std::thread> _threads;
	//线程休眠锁互斥变量
	std::mutex _conditional_mutex;
	//线程环境锁，可以让线程处于休眠或者唤醒状态
	std::condition_variable _conditional_lock;

	int _thread_num;
	int _queue_num;
	//threads close
	bool _shutdown;
};
typedef _thread_pool ThreadPool;

class _thread_work
{
public:
	_thread_work(_thread_pool* pool, int id) :
		_pool(pool),
		_id(id)
	{

	}

	~_thread_work()
	{
		_pool = nullptr;
	}

	// 重载()操作
	void operator()()
	{
		//std::cout << " qidong:  " << _id << std::endl;

		// 定义基础函数类func
		std::function<void()> func;
		// 是否正在取出队列中元素
		bool _is_take = false;

		while (!_pool->_is_shutdown())
		{
			{
				std::unique_lock<std::mutex> lock(_pool->_conditional_mutex);

				_safe_queue<std::function<void()>>* p_queue = task_queue();
				//if (_pool->_queue._empty())
				if(nullptr == p_queue)
				{
					//等待通知开启线程
					_pool->_conditional_lock.wait(lock);
					continue;
				}
				//std::cout << " qidong2" << std::endl;
				_is_take = p_queue->_front(func);
			}
			if (_is_take)
			{
				func();
				_is_take = false;
			}
		}
	}

	int thread_id()
	{
		return _id;
	}

private:
	_safe_queue<std::function<void()>>* task_queue()
	{
		for (auto iter : _pool->_queues_array)
		{
			if (!iter->_empty())
			{
				return iter;
			}
		}
		return nullptr;
	}

	//thread id
	int _id;
	
	//所属
	_thread_pool* _pool;

};






#endif // !THREAD_POOL










