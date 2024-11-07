#include "runnable_task.h"

runnable_task::runnable_task(std::function<void()> func, QObject *parent)
    : QObject{parent}
{
    _func = func;
}

void runnable_task::run()
{
    _func();
}
