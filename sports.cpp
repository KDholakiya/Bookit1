#include "sports.h"
#include "ui_sports.h"
#include "datavendor.h"
#include "eventhandler.h"
Sports::Sports(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Sports)
{
    ui->setupUi(this);
    DataVendor("sports","tomorrow",ui->tomorrow_sports_wrapper,this);
    DataVendor("sports","next_weekend",ui->nextweekend_sports_wrapper,this);
    DataVendor("sports","this_weekend",ui->thisweekend_sports_wrapper,this);
    DataVendor("sports","today",ui->today_sports_wrapper,this);
}

Sports::~Sports()
{
    delete ui;
}
bool Sports::eventFilter(QObject *obj, QEvent *event)
{
    EventHandler(obj,event,this,ui->frame,ui->SportsLayout);
    return 0;
}
