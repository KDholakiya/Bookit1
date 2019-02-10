#ifndef PLAYS_H
#define PLAYS_H

#include <QFrame>

namespace Ui {
class Plays;
}

class Plays : public QFrame
{
    Q_OBJECT

public:
    explicit Plays(QWidget *parent = nullptr);
    ~Plays();
protected:
    bool eventFilter(QObject *obj,QEvent *event);
private:
    Ui::Plays *ui;
};

#endif // PLAYS_H
