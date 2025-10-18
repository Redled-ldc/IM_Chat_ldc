/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "clickedlabel.h"
#include "timerbtn.h"

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QLabel *err_tip;
    QHBoxLayout *horizontalLayout;
    QLabel *user_label;
    QLineEdit *user_edit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *email_label;
    QLineEdit *email_edit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *pass_label;
    QLineEdit *pass_edit;
    ClickedLabel *pass_visible;
    QHBoxLayout *horizontalLayout_7;
    QLabel *confirm_label;
    QLineEdit *confirm_edit;
    ClickedLabel *confirm_visible;
    QHBoxLayout *horizontalLayout_8;
    QLabel *varify_label;
    QLineEdit *varify_edit;
    TimerBtn *getbtn;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *sure_btn;
    QPushButton *cancel_btn;
    QSpacerItem *verticalSpacer_3;
    QWidget *page_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_5;
    QLabel *tip1_lb;
    QLabel *tip2_lb;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *return_btn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_7;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName("RegisterDialog");
        RegisterDialog->resize(300, 500);
        RegisterDialog->setMinimumSize(QSize(300, 500));
        RegisterDialog->setMaximumSize(QSize(300, 500));
        verticalLayout_2 = new QVBoxLayout(RegisterDialog);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(RegisterDialog);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        widget = new QWidget(page);
        widget->setObjectName("widget");
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        err_tip = new QLabel(widget);
        err_tip->setObjectName("err_tip");
        err_tip->setStyleSheet(QString::fromUtf8(""));
        err_tip->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(err_tip);


        verticalLayout_3->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        user_label = new QLabel(page);
        user_label->setObjectName("user_label");
        user_label->setMinimumSize(QSize(25, 25));

        horizontalLayout->addWidget(user_label);

        user_edit = new QLineEdit(page);
        user_edit->setObjectName("user_edit");
        user_edit->setMinimumSize(QSize(0, 25));
        user_edit->setMaximumSize(QSize(16777215, 25));
        user_edit->setEchoMode(QLineEdit::EchoMode::Normal);

        horizontalLayout->addWidget(user_edit);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        email_label = new QLabel(page);
        email_label->setObjectName("email_label");
        email_label->setMinimumSize(QSize(25, 25));

        horizontalLayout_5->addWidget(email_label);

        email_edit = new QLineEdit(page);
        email_edit->setObjectName("email_edit");
        email_edit->setMinimumSize(QSize(0, 25));
        email_edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_5->addWidget(email_edit);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        pass_label = new QLabel(page);
        pass_label->setObjectName("pass_label");
        pass_label->setMinimumSize(QSize(0, 25));

        horizontalLayout_6->addWidget(pass_label);

        pass_edit = new QLineEdit(page);
        pass_edit->setObjectName("pass_edit");
        pass_edit->setMinimumSize(QSize(0, 25));
        pass_edit->setMaximumSize(QSize(16777215, 25));
        pass_edit->setEchoMode(QLineEdit::EchoMode::PasswordEchoOnEdit);

        horizontalLayout_6->addWidget(pass_edit);

        pass_visible = new ClickedLabel(page);
        pass_visible->setObjectName("pass_visible");
        pass_visible->setMinimumSize(QSize(20, 20));
        pass_visible->setMaximumSize(QSize(20, 20));

        horizontalLayout_6->addWidget(pass_visible);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        confirm_label = new QLabel(page);
        confirm_label->setObjectName("confirm_label");
        confirm_label->setMinimumSize(QSize(0, 25));

        horizontalLayout_7->addWidget(confirm_label);

        confirm_edit = new QLineEdit(page);
        confirm_edit->setObjectName("confirm_edit");
        confirm_edit->setMinimumSize(QSize(0, 25));
        confirm_edit->setMaximumSize(QSize(16777215, 25));
        confirm_edit->setEchoMode(QLineEdit::EchoMode::PasswordEchoOnEdit);

        horizontalLayout_7->addWidget(confirm_edit);

        confirm_visible = new ClickedLabel(page);
        confirm_visible->setObjectName("confirm_visible");
        confirm_visible->setMinimumSize(QSize(20, 20));
        confirm_visible->setMaximumSize(QSize(20, 20));

        horizontalLayout_7->addWidget(confirm_visible);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        varify_label = new QLabel(page);
        varify_label->setObjectName("varify_label");
        varify_label->setMinimumSize(QSize(0, 25));

        horizontalLayout_8->addWidget(varify_label);

        varify_edit = new QLineEdit(page);
        varify_edit->setObjectName("varify_edit");
        varify_edit->setMinimumSize(QSize(0, 25));

        horizontalLayout_8->addWidget(varify_edit);

        getbtn = new TimerBtn(page);
        getbtn->setObjectName("getbtn");
        getbtn->setMinimumSize(QSize(0, 25));
        getbtn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_8->addWidget(getbtn);


        verticalLayout_3->addLayout(horizontalLayout_8);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        sure_btn = new QPushButton(page);
        sure_btn->setObjectName("sure_btn");
        sure_btn->setMinimumSize(QSize(0, 25));
        sure_btn->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_9->addWidget(sure_btn);

        cancel_btn = new QPushButton(page);
        cancel_btn->setObjectName("cancel_btn");
        cancel_btn->setMinimumSize(QSize(0, 25));

        horizontalLayout_9->addWidget(cancel_btn);


        verticalLayout_3->addLayout(horizontalLayout_9);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        layoutWidget = new QWidget(page_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(1, 1, 291, 481));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_5);

        tip1_lb = new QLabel(layoutWidget);
        tip1_lb->setObjectName("tip1_lb");
        tip1_lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_5->addWidget(tip1_lb);

        tip2_lb = new QLabel(layoutWidget);
        tip2_lb->setObjectName("tip2_lb");
        tip2_lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_5->addWidget(tip2_lb);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(88, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        return_btn = new QPushButton(layoutWidget);
        return_btn->setObjectName("return_btn");
        return_btn->setMaximumSize(QSize(100, 50));

        horizontalLayout_2->addWidget(return_btn);

        horizontalSpacer_2 = new QSpacerItem(88, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout_2);

        verticalSpacer_7 = new QSpacerItem(20, 68, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_7);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(RegisterDialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QCoreApplication::translate("RegisterDialog", "Dialog", nullptr));
        err_tip->setText(QString());
        user_label->setText(QCoreApplication::translate("RegisterDialog", "\347\224\250\346\210\267\357\274\232", nullptr));
        email_label->setText(QCoreApplication::translate("RegisterDialog", "\351\202\256\347\256\261\357\274\232", nullptr));
        pass_label->setText(QCoreApplication::translate("RegisterDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        pass_visible->setText(QString());
        confirm_label->setText(QCoreApplication::translate("RegisterDialog", "\347\241\256\350\256\244\357\274\232", nullptr));
        confirm_visible->setText(QString());
        varify_label->setText(QCoreApplication::translate("RegisterDialog", "\351\252\214\350\257\201\347\240\201\357\274\232", nullptr));
        getbtn->setText(QCoreApplication::translate("RegisterDialog", "\350\216\267\345\217\226", nullptr));
        sure_btn->setText(QCoreApplication::translate("RegisterDialog", "\347\241\256\350\256\244", nullptr));
        cancel_btn->setText(QCoreApplication::translate("RegisterDialog", "\345\217\226\346\266\210", nullptr));
        tip1_lb->setText(QCoreApplication::translate("RegisterDialog", "\346\263\250\345\206\214\346\210\220\345\212\237\357\274\2145s\345\220\216\350\277\224\345\233\236", nullptr));
        tip2_lb->setText(QCoreApplication::translate("RegisterDialog", "\345\217\257\347\202\271\345\207\273\346\214\211\351\222\256\357\274\214\350\277\224\345\233\236\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
        return_btn->setText(QCoreApplication::translate("RegisterDialog", "\350\277\224\345\233\236\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
