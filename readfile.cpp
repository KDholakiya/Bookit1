#include "readfile.h"
#include <QFile>
#include <QTextStream>
QList<QString> ReadFile::Read(QString File,QString path)
{
    QFile file(File);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&file);
    QList<QString>List;
    while (!in.atEnd())
    {
        if(in.readLine()==path){
            in.readLine();
            for(int i=0;i<8;i++){
                List.append(in.readLine());
            }
            break;
        }
    }
    return List;
}
