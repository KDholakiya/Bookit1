#include "info.h"
#include "ui_info.h"
#include <QPixmap>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QGraphicsDropShadowEffect>
#include "readfile.h"
#include <QMessageBox>
Info::Info(QWidget *parent) :
    QFrame(parent),
ui(new Ui::Info){
    ui->setupUi(this);

}

Info::~Info(){
    delete ui;
}

void Info::Adddata(QString path){
    ui->Poster->setStyleSheet("image:url("+path+")");
    ReadFile file;
    QList <QString>Data=file.Read(":/Assets/Data.txt",path);
    if(!Data.isEmpty()){
        QList <QLabel *>Data_Wrapper={ui->Title,ui->Date,ui->Length,ui->Synopsis,ui->Genre,ui->Language,ui->bookPrice};
        if(Data.at(0)=="Sport"){
            ui->Gerne_kind->setText("Venue :");
            ui->Date_kind->setText("Date :");
            ui->Length_kind->setText("Topic :");
        }else if(Data.at(0)=="Event"){
            ui->Gerne_kind->setText("Venue :");
            ui->Date_kind->setText("Date :");
            ui->Length_kind->setText("Timing :");
            ui->Language_kind->setText("Kind Of :");
        }else if(Data.at(0)=="Play"){
            ui->Date_kind->setText("Date :");
            ui->Gerne_kind->setText("Venue :");
            ui->Length_kind->setText("Timing :");
            ui->Language_kind->setText("Type :");
        }else{
            //qDebug()<<path;
        }
        price=Data.last().toInt();
        payable=price;
        incBy=1;
        dataSent={path};
        dataSent.append(Data);
        dataSent.removeAt(5);
        for(int i=0;i<Data_Wrapper.size();i++){
            Data_Wrapper.at(i)->setText(Data.at(i+1));
            //dataSent.append(Data.at(i));
        }
        ui->bookTotal->setText("$"+QString::number(payable));
        ui->bookPrice->setText("$"+QString::number(price));
    }
}

void Info::on_bookAdd_released(){
    if(payable<4999){
        payable=payable+price;
        incBy++;
        ui->BookMinus->setDisabled(0);
        ui->bookTotal->setText("$"+QString::number(payable));
        ui->bookLength->setText(QString::number(incBy));
        if(payable>4999){
            ui->bookAdd->setDisabled(1);
        }
    }
}

void Info::on_BookMinus_released(){
    if(payable!=price){
        payable=payable-price;
        incBy--;
        ui->bookAdd->setDisabled(0);
        ui->bookTotal->setText("$"+QString::number(payable));
        ui->bookLength->setText(QString::number(incBy));
        if(payable==price){
             ui->BookMinus->setDisabled(1);
        }
    }
}

void Info::on_BookBtn_released()
{
    if((!dataHSent.empty()) or (!dataSent.empty())){
        dataHSent={QString::number(price),QString::number(incBy),QString::number(payable)};
        payment=new paymentDialog;
        payment->paymentHeaderReciever(dataHSent);
        payment->paymentDetailReciever(dataSent);
        payment->exec();
        dataHSent.clear();
    }
}
