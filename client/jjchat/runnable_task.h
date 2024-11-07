#ifndef RUNNABLE_TASK_H
#define RUNNABLE_TASK_H

#include <QObject>
#include <QRunnable>

#include <functional>

class runnable_task : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit runnable_task(std::function<void()> func, QObject *parent = nullptr);

protected:
    void run();

signals:

private:
    std::function<void()> _func;
};

#endif // RUNNABLE_TASK_H
