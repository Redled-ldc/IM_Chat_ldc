#ifndef HTTPMGR_H
#define HTTPMGR_H
#include "singleton.h"
#include <QString>
#include <QUrl>
#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>
//CRTP
class HttpMgr:public QObject,public Singleton <HttpMgr>,public std::enable_shared_from_this<HttpMgr>
{
    Q_OBJECT
public:
     ~HttpMgr();
     void PostHttpReq(QUrl url,QJsonObject json,ReqId Req_id,Modules mod);//send func
private:
    friend class Singleton<HttpMgr>;//声明为友元
    HttpMgr();
    QNetworkAccessManager _manager;//http

private slots:
    void slot_http_finish(ReqId id, QString res,ErrorCode err,Modules mod );

signals:
     void sig_http_finish(ReqId id, QString res,ErrorCode err,Modules mod );//http send finished signals
     void sig_reg_mod_finish(ReqId id, QString res,ErrorCode err);
     void sig_reset_mod_finish(ReqId id, QString res,ErrorCode err);
     void sig_login_mod_finish(ReqId id,QString res,ErrorCode err);

};

#endif // HTTPMGR_He
