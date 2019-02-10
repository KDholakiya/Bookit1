#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>
#include <QFrame>
#include <QLayout>
class EventHandler
{
public:
    EventHandler(QObject *obj,QEvent *event,QWidget *parant,QFrame *Frame,QLayout *Layout);
};

#endif // EVENTHANDLER_H
