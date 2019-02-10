#include "eventhandler.h"
#include <QEvent>
#include "info.h"
#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QGraphicsBlurEffect>
EventHandler::EventHandler(QObject *obj,QEvent *event,QWidget *ui,QFrame *Frame,QLayout *layout)
{
    if(event->type()==QEvent::MouseButtonRelease){
        Frame->hide();
        Info *Model=new Info;
        QString b=obj->objectName();
        Model->Adddata(b);
        layout->addWidget(Model);
    }
    if(event->type()==QEvent::Enter || event->type()==QEvent::Leave){
        QWidget *wid=ui->findChild<QLabel *>(obj->objectName());
        QGraphicsBlurEffect *blur=new QGraphicsBlurEffect;
        blur->setBlurRadius(0);
        if(event->type()==QEvent::Enter){
            blur->setBlurRadius(2);
            wid->setGraphicsEffect(blur);
        }
        if(event->type()==QEvent::Leave){
            wid->setGraphicsEffect(blur);
        }
    }
}
