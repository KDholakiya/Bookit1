#ifndef INFO_H
#define INFO_H

#include <QFrame>
#include "paymentdialog.h"

namespace Ui {
class Info;
}

class Info : public QFrame
{
    Q_OBJECT

public:
    explicit Info(QWidget *parent = nullptr);
    ~Info();
    void Adddata(QString path);

private slots:
    void on_bookAdd_released();

    void on_BookMinus_released();

    void on_BookBtn_released();

private:
    Ui::Info *ui;
    QList<QString> dataSent;
    QList<QString> dataHSent;
    paymentDialog *payment;
    int price;
    int payable;
    int incBy;
};

#endif // INFO_H
