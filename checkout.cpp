#include "checkout.h"
#include "ui_checkout.h"
#include <QMessageBox>
#include "paymentdialog.h"
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QDateTime>
checkout::checkout(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::checkout)
{
    ui->setupUi(this);
    ui->cardnmbr->setValidator( new QDoubleValidator(0, 100, 2, this) );
    ui->cvv->setValidator( new QDoubleValidator(0, 100, 2, this) );
}

checkout::~checkout()
{
    delete ui;
}

void checkout::total(int total)
{
    ui->Amount->setText("$"+QString::number(total));

}

void checkout::on_creditPay_released()
{
    ui->creditPay->setStyleSheet("border:2px solid rgb(89, 65, 169); border-radius:7px;background-color:rgb(89, 65, 169);");
    ui->deibitPay->setStyleSheet("border:2px solid rgb(89, 65, 169);border-radius:7px;");
    ui->cardNumbertype->setText("Enter Creditcard Number :");
}

void checkout::on_deibitPay_released()
{
    ui->deibitPay->setStyleSheet("border:2px solid rgb(89, 65, 169); border-radius:7px;background-color:rgb(89, 65, 169);");
    ui->creditPay->setStyleSheet("border:2px solid rgb(89, 65, 169);border-radius:7px;");
    ui->cardNumbertype->setText("Enter Debitcard Number :");
}

void checkout::on_pay_released()
{
    if(ui->cardnmbr->text().length()==16 and ui->cvv->text().length()==5 and ui->exMonth->currentIndex()!=0 and ui->exYear->currentIndex()!=0){
        QList<QString>a={ui->cardnmbr->text(),ui->exMonth->currentText(),ui->exYear->currentText(),ui->cvv->text()};
        paymentDetails.append(a);
        invoiceCreater();
    }else{
        QMessageBox::information(this,"Incomplete Info","Please Fill  All Fields To Process Further");
    }
}

void checkout::on_pushButton_released()
{
    this->parentWidget()->hide();
}

void checkout::invoiceCreater()
{
    if(!paymentDetails.empty() and !ticketDetail.empty()){
        QDir *dir=new QDir;
        bool isok=false;
        if(!dir->exists(dir->currentPath()+"/Invoices")){
            if(dir->mkdir(dir->currentPath()+"/Invoices")){
                isok=true;
            }else{
                isok=false;
            }
        }else{
            isok=true;
        }
        if(isok){
            QString filename=ticketDetail.at(0);
            QFile file(dir->currentPath()+"/Invoices/"+filename.remove(QRegExp("[^a-zA-Z\\d\\s]"))+".txt");
            QDateTime time;
            ticketDetail.append(time.currentDateTime().toString());
            QList<QString> ticketheaders={"Show",
                                          "Gerne",
                                          "date",
                                          "time",
                                          "Place",
                                          "Booking Time"};
            QList<QString> paymentheaders={"Tickets",
                                           "Price",
                                           "Tickettotal",
                                           "ConviniceFees:",
                                           "Gst:","TotalOrder:",
                                           "Card Number:",
                                           "ExpiryDate\n\tMonth",
                                           "\tYear","cvv"};
            if(file.open(QFile::WriteOnly | QFile::Text)){
                QTextStream out(&file);
                for(int i=0;i<ticketDetail.size();++i){
                    out<<ticketheaders.at(i)<<"\n\t"<<ticketDetail.at(i)<<"\n\n";
                }
                for(int i=0;i<paymentDetails.size();++i){
                    out<<paymentheaders.at(i)<<"\n\t"<<paymentDetails.at(i)<<"\n\n";
                }
                QMessageBox::information(this,"Thank you For Chosing Us..",
                                         "Your Ticket(s) Will Be Sent To You Soon");
                this->parentWidget()->hide();
                file.flush();
                file.close();
            }
        }
    }
}
