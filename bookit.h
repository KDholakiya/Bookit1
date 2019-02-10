#ifndef BOOKIT_H
#define BOOKIT_H

#include <QMainWindow>
#include <QPixmap>
namespace Ui {
class BookIt;
}

class BookIt : public QMainWindow
{
    Q_OBJECT

public:
    explicit BookIt(QWidget *parent = nullptr);
    ~BookIt();
protected:
     bool eventFilter(QObject *obj, QEvent *event);
     void setbg();
     void InstallFilter();
     void showwid(QObject *obj);
private slots:
     void on_backBtn_clicked();
     void on_minimize_pressed();

     void on_maximize_released();

     void on_close_released();

     void on_pushButton_released();

private:
    Ui::BookIt *ui;
    QWidget *wid_main;
};



#endif // BOOKIT_H
