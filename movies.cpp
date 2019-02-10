#include "movies.h"
#include "ui_movies.h"
#include "datavendor.h"
#include <QDebug>
#include "eventhandler.h"
Movies::Movies(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Movies)
{
    ui->setupUi(this);
    DataVendor("movies","hindi",ui->hindi_movies_wrapper,this);
    DataVendor("movies","english",ui->english_movies_wrapper,this);
    DataVendor("movies","gujarati",ui->gujarati_movies_wrapper,this);
    DataVendor("movies","trending",ui->trending_movies_wrapper,this);
}

Movies::~Movies()
{
    delete ui;
}

bool Movies::eventFilter(QObject *obj, QEvent *event){
    EventHandler(obj,event,this,ui->frame,ui->MoviesLayout);
}

