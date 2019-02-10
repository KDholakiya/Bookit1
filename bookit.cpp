#include "bookit.h"
#include "ui_bookit.h"
#include <QDebug>
#include "events.h"
#include "movies.h"
#include "plays.h"
#include "sports.h"
#include <QPixmap>
#include <QGraphicsDropShadowEffect>
#include <QLabel>
#include <QDebug>
#include <QFile>
#include "about.h"
#include "datareciever.h"
static QWidget *CurrentWidget;
BookIt::BookIt(QWidget *parent):
    QMainWindow(parent,Qt::FramelessWindowHint),
    ui(new Ui::BookIt){
        ui->setupUi(this);
        this->setCentralWidget(ui->widget);
        ui->backBtn->hide();
        setbg();
        InstallFilter();
        this->resize(860,495);
        this->setMinimumSize(this->size());
        QIcon icon(":/img/icons/Untitled-2.png");
        this->setWindowIcon(icon);
    }

BookIt::~BookIt(){
    delete ui;
}
bool BookIt::eventFilter(QObject *obj, QEvent *event){
    if((obj->objectName()=="Movies" or obj->objectName()=="Plays" or obj->objectName()=="Events" or obj->objectName()=="Sports")){
        if(event->type()==QEvent::MouseButtonRelease){
            ui->backBtn->show();
            ui->whatondispay->setText(obj->objectName());
            ui->menu->hide();
            showwid(obj);
            dataReciever request("sdf");
        }
        if(event->type()==QEvent::Enter or event->type()==QEvent::Leave or event->type()==QEvent::MouseButtonPress){
            QList<QWidget *> widlist={ui->Movies,ui->Sports,ui->Events,ui->Plays};
            QList<QPointF > offset={QPointF(-4,-4),QPointF(4,-4),QPointF(-4,4),QPointF(4,4)};
            QWidget *wid=findChild<QLabel *>(obj->objectName());
            QGraphicsDropShadowEffect *shadow=new QGraphicsDropShadowEffect;
            shadow->setBlurRadius(4);
            shadow->setColor(QColor("#adadad"));

            if(event->type()==QEvent::Enter){
              for(int i=0;i<widlist.size();++i){
                  if(widlist.at(i)==obj){
                      shadow->setOffset(offset.at(i));
                      wid->setGraphicsEffect(shadow);
                      break;
                  }
              }
            }
            if(event->type()==QEvent::MouseButtonPress){
                wid->graphicsEffect()->setEnabled(false);
            }
            if(event->type()==QEvent::Leave){
                for(int i=0;i<widlist.size();++i){
                    if(widlist.at(i)==obj){
                        shadow->setOffset(-offset.at(i));
                        wid->setGraphicsEffect(shadow);
                        break;
                    }
                }
            }
        }
    }
}

void BookIt::setbg(){
    QList<QWidget *> widlist={ui->Movies,ui->Sports,ui->Events,ui->Plays};
    QList<QString> url={":/img/bg/movies.jpg",":/img/bg/Sports.jpg",":/img/bg/Concert.jpg",":/img/bg/Plays.jpg"};
    QList<QPointF> offset={QPointF(-5,-5),QPointF(5,-5),QPointF(-5,5),QPointF(5,5)};
    for(int i=0;i<widlist.size();++i){
        QFile file(url.at(i));
        widlist.at(i)->setStyleSheet("background-image:url(\""+url.at(i)+"\"); background-position: center;color:'#000';border:0px solid #000;border-radius:10;");
        QGraphicsDropShadowEffect *shadow=new QGraphicsDropShadowEffect(this);
        shadow->setColor(QColor("#adadad"));
        shadow->setOffset(-(offset.at(i)));
        shadow->setBlurRadius(qreal(5));
        widlist.at(i)->setGraphicsEffect(shadow);
    }
}
void BookIt::InstallFilter(){
    QList<QWidget *> widlist={ui->Movies,ui->Sports,ui->Events,ui->Plays,centralWidget(),this,ui->header};
    for(int i=0;i<widlist.size();++i){
        widlist.at(i)->installEventFilter(this);
    }
}
void BookIt::showwid(QObject *obj){
    if(obj->objectName()=="Movies"){
        wid_main=new Movies;
    }else if(obj->objectName()=="Plays"){
        wid_main=new Plays;
    }else if(obj->objectName()=="Events"){
        wid_main=new Events;
    }else{
        wid_main=new Sports;
    }
    ui->body_Layout->addWidget(wid_main);
    CurrentWidget=wid_main;
}

void BookIt::on_backBtn_clicked(){
    if(QWidget *delwid=ui->body->findChild<QFrame *>("Info")){
        delete delwid;
        QWidget *showwid=ui->body->findChild<QFrame *>("frame");
        showwid->show();
    }else{
        delete CurrentWidget;
        ui->backBtn->hide();
        ui->menu->show();
        ui->whatondispay->setText("What You Wanna Watch?");
    }
}


void BookIt::on_minimize_pressed()
{
    showMinimized();
}

void BookIt::on_maximize_released()
{
    if(window()->isMaximized()){
        showNormal();
    }else{
        showMaximized();
    }
}

void BookIt::on_close_released()
{
    close();
}

void BookIt::on_pushButton_released()
{
    About a;
    a.setModal(true);
    a.exec();
}
