/********************************************************************************
** Form generated from reading UI file 'OnlineUser.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONLINEUSER_H
#define UI_ONLINEUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OnlineUser
{
public:
    QHBoxLayout *horizontalLayout_3;
    QPushButton *UserLogo;
    QVBoxLayout *UserInfoArea;
    QHBoxLayout *UserInfo;
    QLabel *UserName;
    QLabel *UserID;
    QHBoxLayout *Info;
    QLabel *UserAddr;
    QLabel *UserPort;

    void setupUi(QWidget *OnlineUser)
    {
        if (OnlineUser->objectName().isEmpty())
            OnlineUser->setObjectName("OnlineUser");
        OnlineUser->resize(184, 52);
        horizontalLayout_3 = new QHBoxLayout(OnlineUser);
        horizontalLayout_3->setSpacing(1);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(2, 2, 2, 2);
        UserLogo = new QPushButton(OnlineUser);
        UserLogo->setObjectName("UserLogo");
        UserLogo->setMinimumSize(QSize(40, 40));
        UserLogo->setMaximumSize(QSize(40, 40));
        UserLogo->setIconSize(QSize(40, 40));

        horizontalLayout_3->addWidget(UserLogo);

        UserInfoArea = new QVBoxLayout();
        UserInfoArea->setSpacing(2);
        UserInfoArea->setObjectName("UserInfoArea");
        UserInfo = new QHBoxLayout();
        UserInfo->setObjectName("UserInfo");
        UserName = new QLabel(OnlineUser);
        UserName->setObjectName("UserName");
        UserName->setMinimumSize(QSize(80, 0));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        UserName->setFont(font);

        UserInfo->addWidget(UserName);

        UserID = new QLabel(OnlineUser);
        UserID->setObjectName("UserID");
        UserID->setMinimumSize(QSize(40, 0));

        UserInfo->addWidget(UserID);


        UserInfoArea->addLayout(UserInfo);

        Info = new QHBoxLayout();
        Info->setObjectName("Info");
        UserAddr = new QLabel(OnlineUser);
        UserAddr->setObjectName("UserAddr");
        UserAddr->setMinimumSize(QSize(80, 0));

        Info->addWidget(UserAddr);

        UserPort = new QLabel(OnlineUser);
        UserPort->setObjectName("UserPort");

        Info->addWidget(UserPort);


        UserInfoArea->addLayout(Info);


        horizontalLayout_3->addLayout(UserInfoArea);


        retranslateUi(OnlineUser);

        QMetaObject::connectSlotsByName(OnlineUser);
    } // setupUi

    void retranslateUi(QWidget *OnlineUser)
    {
        OnlineUser->setWindowTitle(QCoreApplication::translate("OnlineUser", "Form", nullptr));
        UserLogo->setText(QCoreApplication::translate("OnlineUser", "Logo", nullptr));
        UserName->setText(QCoreApplication::translate("OnlineUser", "\347\224\250\346\210\267\346\230\265\347\247\260", nullptr));
        UserID->setText(QCoreApplication::translate("OnlineUser", "ID", nullptr));
        UserAddr->setText(QCoreApplication::translate("OnlineUser", "\347\275\221\347\273\234\345\234\260\345\235\200", nullptr));
        UserPort->setText(QCoreApplication::translate("OnlineUser", "\347\253\257\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OnlineUser: public Ui_OnlineUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONLINEUSER_H
