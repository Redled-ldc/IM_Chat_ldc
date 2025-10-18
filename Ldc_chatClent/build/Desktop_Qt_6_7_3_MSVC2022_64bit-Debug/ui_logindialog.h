/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <clickedlabel.h>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *head_widget;
    QGridLayout *gridLayout;
    QLabel *head_label;
    QLabel *err_tip;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *email_lb;
    QLineEdit *email_edit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *pass_label;
    QLineEdit *pass_edit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    ClickedLabel *forget_label;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *login_btn;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *reg_btn;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        LoginDialog->resize(300, 500);
        LoginDialog->setMinimumSize(QSize(300, 500));
        LoginDialog->setMaximumSize(QSize(300, 500));
        verticalLayout_2 = new QVBoxLayout(LoginDialog);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(7);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        head_widget = new QWidget(LoginDialog);
        head_widget->setObjectName("head_widget");
        gridLayout = new QGridLayout(head_widget);
        gridLayout->setObjectName("gridLayout");
        head_label = new QLabel(head_widget);
        head_label->setObjectName("head_label");
        head_label->setMinimumSize(QSize(200, 200));
        head_label->setMaximumSize(QSize(200, 200));
        head_label->setPixmap(QPixmap(QString::fromUtf8(":/res/ice.png")));
        head_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(head_label, 0, 0, 1, 1);


        verticalLayout->addWidget(head_widget);

        err_tip = new QLabel(LoginDialog);
        err_tip->setObjectName("err_tip");
        err_tip->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(err_tip);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        email_lb = new QLabel(LoginDialog);
        email_lb->setObjectName("email_lb");
        email_lb->setMinimumSize(QSize(25, 25));

        horizontalLayout->addWidget(email_lb);

        email_edit = new QLineEdit(LoginDialog);
        email_edit->setObjectName("email_edit");
        email_edit->setMinimumSize(QSize(25, 25));

        horizontalLayout->addWidget(email_edit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pass_label = new QLabel(LoginDialog);
        pass_label->setObjectName("pass_label");

        horizontalLayout_2->addWidget(pass_label);

        pass_edit = new QLineEdit(LoginDialog);
        pass_edit->setObjectName("pass_edit");
        pass_edit->setMinimumSize(QSize(25, 25));
        pass_edit->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_2->addWidget(pass_edit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        forget_label = new ClickedLabel(LoginDialog);
        forget_label->setObjectName("forget_label");
        forget_label->setMinimumSize(QSize(25, 25));

        horizontalLayout_3->addWidget(forget_label);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        login_btn = new QPushButton(LoginDialog);
        login_btn->setObjectName("login_btn");
        login_btn->setMinimumSize(QSize(100, 30));

        horizontalLayout_4->addWidget(login_btn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        reg_btn = new QPushButton(LoginDialog);
        reg_btn->setObjectName("reg_btn");
        reg_btn->setMinimumSize(QSize(100, 30));

        horizontalLayout_5->addWidget(reg_btn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        head_label->setText(QString());
        err_tip->setText(QCoreApplication::translate("LoginDialog", "Hello", nullptr));
        email_lb->setText(QCoreApplication::translate("LoginDialog", "\351\202\256\347\256\261", nullptr));
        pass_label->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201", nullptr));
        forget_label->setText(QCoreApplication::translate("LoginDialog", "\345\277\230\350\256\260\345\257\206\347\240\201", nullptr));
        login_btn->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\351\231\206", nullptr));
        reg_btn->setText(QCoreApplication::translate("LoginDialog", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
