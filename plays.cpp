#include "plays.h"
#include "ui_plays.h"
#include "datavendor.h"
#include "eventhandler.h"

Plays::Plays(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Plays)
{
    ui->setupUi(this);
    DataVendor("plays","tomorrow",ui->tomorow_plays_wrapper,this);
    DataVendor("plays","next_weekend",ui->nextweekend_plays_wrapper,this);
    DataVendor("plays","this_weekend",ui->thisweekend_plays_wrapper,this);
    DataVendor("plays","today",ui->today_plays_wrapper,this);
}

Plays::~Plays()
{
    delete ui;
}
bool Plays::eventFilter(QObject *obj, QEvent *event)
{
    EventHandler(obj,event,this,ui->frame,ui->PlaysLayout);
}
