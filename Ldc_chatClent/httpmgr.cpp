#include "httpmgr.h"

HttpMgr::~HttpMgr()
{

}

HttpMgr::HttpMgr()
{
    connect(this,&HttpMgr::sig_http_finish,this,&HttpMgr::slot_http_finish);
}

void HttpMgr::PostHttpReq(QUrl url, QJsonObject json, ReqId Req_id, Modules mod)
{
    //json 序列化
    QByteArray data=QJsonDocument(json).toJson();
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");//请求类型
    request.setHeader(QNetworkRequest::ContentLengthHeader,QByteArray::number(data.length()));//长度
    auto self =shared_from_this();
    QNetworkReply * reply =_manager.post(request,data);//发送
    QObject::connect(reply,&QNetworkReply::finished,[reply,self,Req_id,mod](){
        //错误处理

        if(reply->error()!=QNetworkReply::NoError)
        {
           // qDebug()<<reply->errorString();
            //发送信号通知完成
            emit self->sig_http_finish(Req_id,"",ErrorCode::ERR_NETWORK,mod);
            reply->deleteLater();
            return ;
        }
        //无错误
        QString res=reply->readAll();
        //发送信号通知完成
        if(res.isEmpty()){
           qDebug()<<"server is empty";
            emit self->sig_http_finish(Req_id, "", ErrorCode::ERR_NETWORK, mod);
        }else{
        emit self->sig_http_finish(Req_id,res,ErrorCode::SUCCESS,mod);
        }
        reply->deleteLater();
        return ;
    });

}

void HttpMgr::slot_http_finish(ReqId id, QString res, ErrorCode err, Modules mod)
{
    //注册
    if(mod==Modules::REGISTERMOD)
    {
       //发送指定模块http的响应结束了
        emit sig_reg_mod_finish(id,res,err);
    }
    //重置
    if(mod==Modules::RESETMOD)
    {
        emit sig_reset_mod_finish(id,res,err);
    }
    //登录
    if(mod==Modules::LOGINMOD)
    {
        emit sig_login_mod_finish(id,res,err);
    }
}
