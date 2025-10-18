#include "mainwindow.h"
#include <QApplication>
#include<QFile>
#include <global.h>
/********************************************************
 *   @file          main.cpp
 *   @brief         Chat Main Window
 *
 *   @author        Ldc
 *   @date          2025/03/31
 *   @history
 *********************************************************/


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile qss(":/style/stylesheet.qss");
    if(qss.open(QFile::ReadOnly))
    {
         qDebug("open file sucess");

        QString style =QLatin1String(qss.readAll());
         a.setStyleSheet(style);
        qss.close();
    }
    else
    {
        qDebug("open file faile");
    }
    QString fileName="config.ini";
    QString app_path=QCoreApplication::applicationDirPath();
    QString config_path=QDir::toNativeSeparators( (app_path+QDir::separator()+fileName));
    QSettings settings(config_path,QSettings::IniFormat);
    MainWindow w;
    QString gate_host=settings.value("GateServer/host").toString();
    QString gate_port=settings.value("GateServer/port").toString();
    gate_url_prefix="http://"+gate_host+":"+gate_port;
    w.show();
    return a.exec();
}
