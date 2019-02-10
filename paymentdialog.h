#ifndef PAYMENTDIALOG_H
#define PAYMENTDIALOG_H

#include <QDialog>
#include "checkout.h"
namespace Ui {
class paymentDialog;
}

class paymentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit paymentDialog(QWidget *parent = nullptr);
    void paymentDetailReciever(QList<QString> Data);
    void paymentHeaderReciever(QList<QString> HData);
    ~paymentDialog();
private slots:
    void on_pushButton_released();

    void on_PayProcess_released();

private:
    Ui::paymentDialog *ui;
    double total;
};

#endif // PAYMENTDIALOG_H
