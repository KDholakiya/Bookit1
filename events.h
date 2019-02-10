#ifndef EVENTS_H
#define EVENTS_H

#include <QFrame>

namespace Ui {
    class Events;
}

class Events : public QFrame
{
    Q_OBJECT

public:
    explicit Events(QWidget *parent = nullptr);
    ~Events();
protected:
    bool eventFilter(QObject *obj,QEvent *event);
private:
    Ui::Events *ui;
};

#endif // EVENTS_H
