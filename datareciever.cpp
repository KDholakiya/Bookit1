#include "datareciever.h"
#include <QtNetwork>
#include <QtDebug>
dataReciever::dataReciever(QString request)
{
    if(!request.isEmpty()){
        QNetworkRequest req(QUrl("http://localhost/bookit/rest/?select/movies/trending"));
        req.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
        QNetworkAccessManager nam;
        QNetworkReply *reply=nam.get(req);
        while(!reply->isFinished()){
            qApp->processEvents();
        }
        if(!reply->error()){
            QByteArray byteArr=reply->readAll();
            QJsonDocument json = QJsonDocument::fromJson(byteArr);
            if(json.isEmpty()){
                qDebug()<<"404 Data Not Found";
            }else{
               qDebug()<<json;
            }
        }else{
            qDebug()<<reply->error();
        }

    }
}
