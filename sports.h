    #ifndef SPORTS_H
#define SPORTS_H

#include <QFrame>

namespace Ui {
class Sports;
}

class Sports : public QFrame
{
    Q_OBJECT

public:
    explicit Sports(QWidget *parent = nullptr);
    ~Sports();
protected:
    bool eventFilter(QObject *obj,QEvent *event);
private:
    Ui::Sports *ui;
};

#endif // SPORTS_H
