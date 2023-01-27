#include "queuedispatcher.h"

QueueDispatcher::QueueDispatcher()
{
    static std::once_flag onceFlag;
        std::call_once(onceFlag,
                       []()
                       {
                           qRegisterMetaType<ResultHandler>("ResultHandler");
        });
}

void QueueDispatcher::perform(ResultHandler action)
{
    std::vector<int> c;
    action(c);
}

void QueueDispatcher::dispatchNow(ResultHandler func)
{
    QMetaObject::invokeMethod(this, "perform", Qt::QueuedConnection, Q_ARG(ResultHandler, func));
}
