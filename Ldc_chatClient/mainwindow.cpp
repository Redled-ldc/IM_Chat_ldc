#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _login_dlg=new LoginDialog(this);
    setCentralWidget(_login_dlg);
    //_login_dlg->show();
    //创建和注册消息连接
   _login_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    connect(_login_dlg,&LoginDialog::switchRegister,this,&MainWindow::SlotSwitchReg);
   //连接登录界面忘记密码信号
   connect(_login_dlg, &LoginDialog::switchReset, this, &MainWindow::SlotSwitchReset);

}

MainWindow::~MainWindow()
{
    delete ui;
    //if(_login_dlg)
    //{
    //    delete _login_dlg;
    //    _login_dlg=nullptr;
    //}
    // if(_regist_dlg)
    //{
    //    delete _regist_dlg;
    //    _regist_dlg=nullptr;
    //}
}

void MainWindow::SlotSwitchReg()
{
    _reg_dlg=new RegisterDialog(this);


    _reg_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
   // _reg_dlg->hide();


    //连接注册界面返回登录界面的信号
    connect(_reg_dlg,&RegisterDialog::sigSwitchLogin,this,&MainWindow::SlotSwichLogin);
    setCentralWidget(_reg_dlg);
    _login_dlg->hide();
    _reg_dlg->show();
}

void MainWindow::SlotSwichLogin()
{
    //创建一个CentralWidget, 并将其设置为MainWindow的中心部件
    //创建一个CentralWidget, 并将其设置为MainWindow的中心部件
    _login_dlg = new LoginDialog(this);
    _login_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    setCentralWidget(_login_dlg);

    _reg_dlg->hide();
    _login_dlg->show();
    //连接登录界面注册信号
    connect(_login_dlg, &LoginDialog::switchRegister, this, &MainWindow::SlotSwitchReg);
    //连接登录界面忘记密码信号
   connect(_login_dlg, &LoginDialog::switchReset, this, &MainWindow::SlotSwitchReset);

}

void MainWindow::SlotSwichLogin2()
{
    //创建一个CentralWidget, 并将其设置为MainWindow的中心部件
    _login_dlg = new LoginDialog(this);
    _login_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    setCentralWidget(_login_dlg);

    _reset_dlg->hide();
    _login_dlg->show();
    //连接登录界面忘记密码信号
    connect(_login_dlg, &LoginDialog::switchReset, this, &MainWindow::SlotSwitchReset);
    //连接登录界面注册信号
    connect(_login_dlg, &LoginDialog::switchRegister, this, &MainWindow::SlotSwitchReg);
}

void MainWindow::SlotSwitchReset()
{
    //ResetDialog(this);
    //创建一个CentralWidget, 并将其设置为MainWindow的中心部件
    _reset_dlg =new ResetDialog(this);
    _reset_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    setCentralWidget(_reset_dlg);

    _login_dlg->hide();
    _reset_dlg->show();
    //注册返回登录信号和槽函数
    connect(_reset_dlg, &ResetDialog::switchLogin, this, &MainWindow::SlotSwichLogin2);
}
