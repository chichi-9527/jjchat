#include "_thread_pool.h"


void _thread_pool::_init()
{
	for (int i = 0; i < _threads.size(); ++i)
	{
		_threads.at(i) = std::thread(_thread_work(this, i)); 
	}
}
