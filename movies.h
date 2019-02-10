#ifndef MOVIES_H
#define MOVIES_H

#include <QFrame>
#include <QHBoxLayout>
namespace Ui {
class Movies;
}

class Movies : public QFrame
{
    Q_OBJECT

public:
    explicit Movies(QWidget *parent = nullptr);
    ~Movies();
protected:
    bool eventFilter(QObject *obj,QEvent *event);
private:
    Ui::Movies *ui;
    void loadData(QString parant,QString child,QHBoxLayout *layout);
};

#endif // MOVIES_H
