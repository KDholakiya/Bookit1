#include "events.h"
#include "ui_events.h"
#include "datavendor.h"
#include "eventhandler.h"

Events::Events(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Events)
{
    ui->setupUi(this);
    DataVendor("events","tomorrow",ui->tomorrow_event_wrapper,this);
    DataVendor("events","next_weekend",ui->nextweekend_event_wrapper,this);
    DataVendor("events","this_weekend",ui->thisweekend_event_wrapper,this);
    DataVendor("events","today",ui->today_event_wrapper,this);

}

Events::~Events()
{
    delete ui;
}
bool Events::eventFilter(QObject *obj, QEvent *event)
{
    EventHandler(obj,event,this,ui->frame,ui->EventsLayout);
}
