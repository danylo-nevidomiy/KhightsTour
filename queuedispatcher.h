#ifndef QUEUEDISPATCHER_H
#define QUEUEDISPATCHER_H

#include <QObject>
#include <QMetaObject>
#include <mutex>
#include <vector>
//#include <functional>


using ResultHandler = std::function<void(std::vector<int>)>;

class QueueDispatcher : public QObject
{
    Q_OBJECT
public:
    QueueDispatcher();
    void perform(ResultHandler action);
    void dispatchNow(ResultHandler func);
};

#endif // QUEUEDISPATCHER_H
