#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include"global.h"
namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();

private slots:
    //获取信号
    void on_getbtn_clicked();
    void slot_reg_mod_finish(ReqId id, QString res,ErrorCode err);
    //确认注册信号
    void on_sure_btn_clicked();

    void on_return_btn_clicked();

    void on_cancel_btn_clicked();
private:
    void initHttpHandlers();

    void showTip(QString str,bool b_ok);
    void AddTipErr(TipErr te, QString tips);
    void DelTipErr(TipErr te);
    bool checkUserValid();
    bool checkPassValid();
    bool checkEmailValid();
    bool checkVarifyValid();
    bool checkConfirmValid();
    void ChangeTipPage();
    Ui::RegisterDialog *ui;
    QMap<ReqId,std::function<void(const QJsonObject&)>>_handlers;
    QMap<TipErr, QString> _tip_errs;
    QTimer*_countdown_timer;
    int _countdown;
signals:
    void sigSwitchLogin();
};

#endif // REGISTERDIALOG_H
