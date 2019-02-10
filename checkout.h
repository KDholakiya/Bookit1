#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <QFrame>

namespace Ui {
class checkout;
}

class checkout : public QFrame
{
    Q_OBJECT

public:
    explicit checkout(QWidget *parent = nullptr);
    ~checkout();
    void total(int total);
    QList<QString> paymentDetails;
    QList<QString> ticketDetail;
private slots:
    void on_creditPay_released();
    void on_deibitPay_released();
    void on_pay_released();
    void on_pushButton_released();
    void invoiceCreater();
    void on_cardnmbr_textChanged(const QString &arg1);

private:
    Ui::checkout *ui;
};

#endif // CHECKOUT_H
