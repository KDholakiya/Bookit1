#include "datavendor.h"
#include <QDir>
#include <QPixmap>
#include <QLabel>
#include <QGraphicsDropShadowEffect>
#include <QDebug>
DataVendor::DataVendor(QString parant, QString child, QHBoxLayout *layout,QWidget *parantWid)
{
    qDebug()<<"Parant >"<<parant<<" child >"<<child;
    QDir dir(":/img/poster/"+parant+"/"+child+"/","*.jpg");
    if(dir.isEmpty()==false){
        foreach (QFileInfo var, dir.entryInfoList()) {
            QLabel *lab=new QLabel;
            QPixmap pix(var.absoluteFilePath());
            lab->resize(160,244);
            lab->setPixmap(pix.scaled(lab->width(),lab->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
            layout->addWidget(lab);
            lab->setCursor(Qt::PointingHandCursor);
            layout->setAlignment(lab,Qt::AlignHCenter);
            lab->setObjectName(var.absoluteFilePath());
            lab->installEventFilter(parantWid);
        }
    }else{
        QLabel *lab=new QLabel;
        lab->setTextFormat(Qt::RichText);
        lab->setText("<center><h1>We Feel sorry for you...There Is nothing to Entertain you</h1><br><h3>Please Check Again After Few Hours..Hope There's Something Good Content</h3></center>");
        layout->addWidget(lab);
    }
}
