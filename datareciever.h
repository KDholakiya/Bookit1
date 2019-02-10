#ifndef DATARECIEVER_H
#define DATARECIEVER_H
#include <QString>
class dataReciever
{
public:
    dataReciever(QString request);
    QList<QString> getData();
private:
    QList<QString> *ArrayofData;
};

#endif // DATARECIEVER_H
