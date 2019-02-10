#include "bookit.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BookIt w;
    w.show();
    return a.exec();
}
