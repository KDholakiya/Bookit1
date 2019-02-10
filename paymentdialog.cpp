#include "paymentdialog.h"
#include "ui_paymentdialog.h"
paymentDialog::paymentDialog(QWidget *parent) :
    QDialog(parent,Qt::FramelessWindowHint),
    ui(new Ui::paymentDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Checkout");
    QIcon icon(":img/icons/Untitled-2.png");
    this->setWindowIcon(icon);
}

void paymentDialog::paymentDetailReciever(QList<QString> d)
{
    ui->poster->setStyleSheet("image:url("+d.first()+")");
    QList<QLabel *>labs={};
    if(d.at(1)=="Movie"){
        labs={ui->kindTitle,ui->Date,ui->Time};
        ui->langAndGerne->setText(d.at(5)+"-"+d.at(6));
        ui->place->setText("At Your Neareast Theater..");
        ui->kindTicket->setText(d.at(1)+" Ticket");
    }else if(d.at(1)=="Event"){
        labs={ui->kindTitle,ui->Date,ui->Time,ui->place};
        ui->langAndGerne->setText(d.at(6));
        ui->kindTicket->setText(d.at(1)+" Pass");
    }else if(d.at(1)=="Sport"){
        labs={ui->kindTitle,ui->Date,ui->Time,ui->place};
        ui->kindTicket->setText(d.at(1)+" Pass");
    }else{
        labs={ui->kindTitle,ui->Date,ui->Time,ui->place,ui->langAndGerne};
        ui->kindTicket->setText(d.at(1)+" Pass");
    }
    for(int i=0;i<labs.size();++i){
        labs.at(i)->setText(d.at(i+2));
    }
}

void paymentDialog::paymentHeaderReciever(QList<QString> hd)
{
    ui->ticketLength->setText(hd.at(1)+" Tickets *"+hd.at(0)+" =");
    ui->ticketTotal->setText(hd.at(2));
    double convi=hd.at(2).toInt()/10;
    ui->convFees->setText(QString::number(convi));
    double gst=hd.at(2).toInt()/18;
    ui->gst->setText(QString::number(gst));
    total=convi+gst+hd.at(2).toInt();
    ui->totalOrder->setText(QString::number(total));
    ui->totalTicket->setText(hd.at(1));
    ui->PayProcess->setText("Proceed to Pay "+QString::number(total)+"$");
}

paymentDialog::~paymentDialog()
{
    delete ui;
}

void paymentDialog::on_pushButton_released()
{
    close();
}

void paymentDialog::on_PayProcess_released()
{
    checkout *check=new checkout;
    int price=ui->ticketTotal->text().toInt()/ui->totalTicket->text().toInt();
    QList<QString>DataH={ui->totalTicket->text(),QString::number(price),ui->ticketTotal->text(),ui->convFees->text(),ui->gst->text(),ui->totalOrder->text()};
    QList<QString>DataD={ui->kindTitle->text(),ui->langAndGerne->text(),ui->Date->text(),ui->Time->text(),ui->place->text()};
    check->paymentDetails=DataH;
    check->ticketDetail=DataD;
    check->total(total);
    ui->main->hide();
    ui->mainLay->addWidget(check);
}
