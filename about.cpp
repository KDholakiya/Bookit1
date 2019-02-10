#include "about.h"
#include "ui_about.h"
#include <QIcon>
#include <QDesktopServices>
#include <QUrl>
About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    this->setWindowTitle("About Creater");
    QIcon icon(":/img/icons/Untitled-2.png");
    this->setWindowIcon(icon);
}
About::~About()
{
    delete ui;
}
void About::on_linkedin_clicked()
{
    QDesktopServices::openUrl(QUrl("www.linkedin.com/in/keval-dholakiya-652960150/"));
}

void About::on_github_released()
{
    QDesktopServices::openUrl(QUrl("www.github.com/keval47/"));
}

void About::on_twitter_released()
{
    QDesktopServices::openUrl(QUrl("www.twitter.com/kevalDholakiya5"));
}
