/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *LeftArea;
    QHBoxLayout *UserArea;
    QPushButton *UserLogo;
    QVBoxLayout *UserInfoArea;
    QHBoxLayout *UserInfoArea1;
    QLabel *UserName;
    QLabel *UserIdent;
    QSpacerItem *UserSpacer1;
    QHBoxLayout *UserInfoArea2;
    QLabel *Address;
    QLabel *Port;
    QSpacerItem *UserSpacer2;
    QHBoxLayout *SearchArea;
    QLineEdit *SearchEdit;
    QPushButton *SearchButton;
    QListWidget *OnlineListWidget;
    QVBoxLayout *RightArea;
    QLabel *Title;
    QListWidget *RecvMessageWidget;
    QWidget *SendMessageWidget;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *SendMessageEdit;
    QHBoxLayout *ButtonArea;
    QSpacerItem *ButtonSpacer;
    QPushButton *SendButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(725, 502);
        MainWindow->setMinimumSize(QSize(725, 502));
        MainWindow->setMaximumSize(QSize(725, 502));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_4 = new QHBoxLayout(centralwidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        LeftArea = new QVBoxLayout();
        LeftArea->setSpacing(2);
        LeftArea->setObjectName("LeftArea");
        UserArea = new QHBoxLayout();
        UserArea->setObjectName("UserArea");
        UserLogo = new QPushButton(centralwidget);
        UserLogo->setObjectName("UserLogo");
        UserLogo->setMinimumSize(QSize(40, 40));
        UserLogo->setMaximumSize(QSize(40, 40));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::CameraPhoto));
        UserLogo->setIcon(icon);
        UserLogo->setIconSize(QSize(35, 35));

        UserArea->addWidget(UserLogo);

        UserInfoArea = new QVBoxLayout();
        UserInfoArea->setObjectName("UserInfoArea");
        UserInfoArea1 = new QHBoxLayout();
        UserInfoArea1->setObjectName("UserInfoArea1");
        UserName = new QLabel(centralwidget);
        UserName->setObjectName("UserName");

        UserInfoArea1->addWidget(UserName);

        UserIdent = new QLabel(centralwidget);
        UserIdent->setObjectName("UserIdent");

        UserInfoArea1->addWidget(UserIdent);

        UserSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        UserInfoArea1->addItem(UserSpacer1);


        UserInfoArea->addLayout(UserInfoArea1);

        UserInfoArea2 = new QHBoxLayout();
        UserInfoArea2->setObjectName("UserInfoArea2");
        Address = new QLabel(centralwidget);
        Address->setObjectName("Address");

        UserInfoArea2->addWidget(Address);

        Port = new QLabel(centralwidget);
        Port->setObjectName("Port");

        UserInfoArea2->addWidget(Port);

        UserSpacer2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        UserInfoArea2->addItem(UserSpacer2);


        UserInfoArea->addLayout(UserInfoArea2);


        UserArea->addLayout(UserInfoArea);


        LeftArea->addLayout(UserArea);

        SearchArea = new QHBoxLayout();
        SearchArea->setSpacing(0);
        SearchArea->setObjectName("SearchArea");
        SearchArea->setContentsMargins(-1, 5, -1, 5);
        SearchEdit = new QLineEdit(centralwidget);
        SearchEdit->setObjectName("SearchEdit");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SearchEdit->sizePolicy().hasHeightForWidth());
        SearchEdit->setSizePolicy(sizePolicy);
        SearchEdit->setMinimumSize(QSize(70, 30));
        SearchEdit->setMaximumSize(QSize(9999999, 30));
        SearchEdit->setStyleSheet(QString::fromUtf8("#SearchEdit{\n"
"border:1px solid #c0c0c0;\n"
"padding-left:10px;\n"
"}"));

        SearchArea->addWidget(SearchEdit);

        SearchButton = new QPushButton(centralwidget);
        SearchButton->setObjectName("SearchButton");
        sizePolicy.setHeightForWidth(SearchButton->sizePolicy().hasHeightForWidth());
        SearchButton->setSizePolicy(sizePolicy);
        SearchButton->setMinimumSize(QSize(30, 30));
        SearchButton->setMaximumSize(QSize(30, 30));
        SearchButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditFind));
        SearchButton->setIcon(icon1);
        SearchButton->setIconSize(QSize(20, 20));

        SearchArea->addWidget(SearchButton);


        LeftArea->addLayout(SearchArea);

        OnlineListWidget = new QListWidget(centralwidget);
        OnlineListWidget->setObjectName("OnlineListWidget");
        OnlineListWidget->setMinimumSize(QSize(100, 250));
        OnlineListWidget->setMaximumSize(QSize(999999, 500));
        OnlineListWidget->setStyleSheet(QString::fromUtf8("#FriendList{\n"
"margin:2px;\n"
"border:none;\n"
"}"));

        LeftArea->addWidget(OnlineListWidget);

        LeftArea->setStretch(2, 999);

        horizontalLayout_4->addLayout(LeftArea);

        RightArea = new QVBoxLayout();
        RightArea->setObjectName("RightArea");
        Title = new QLabel(centralwidget);
        Title->setObjectName("Title");
        Title->setMinimumSize(QSize(30, 30));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        Title->setFont(font);

        RightArea->addWidget(Title);

        RecvMessageWidget = new QListWidget(centralwidget);
        RecvMessageWidget->setObjectName("RecvMessageWidget");
        RecvMessageWidget->setMinimumSize(QSize(400, 220));
        RecvMessageWidget->setStyleSheet(QString::fromUtf8("#RecvMessageWidget{\n"
"margin:2px;\n"
"border:none;\n"
"}"));

        RightArea->addWidget(RecvMessageWidget);

        SendMessageWidget = new QWidget(centralwidget);
        SendMessageWidget->setObjectName("SendMessageWidget");
        SendMessageWidget->setMinimumSize(QSize(0, 100));
        verticalLayout = new QVBoxLayout(SendMessageWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        SendMessageEdit = new QPlainTextEdit(SendMessageWidget);
        SendMessageEdit->setObjectName("SendMessageEdit");
        SendMessageEdit->setMinimumSize(QSize(400, 105));
        QFont font1;
        font1.setBold(false);
        font1.setKerning(true);
        SendMessageEdit->setFont(font1);
        SendMessageEdit->setStyleSheet(QString::fromUtf8("#SendMessageEdit{\n"
"margin:2px;\n"
"border:none;\n"
"}"));

        verticalLayout->addWidget(SendMessageEdit);

        ButtonArea = new QHBoxLayout();
        ButtonArea->setObjectName("ButtonArea");
        ButtonSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        ButtonArea->addItem(ButtonSpacer);

        SendButton = new QPushButton(SendMessageWidget);
        SendButton->setObjectName("SendButton");

        ButtonArea->addWidget(SendButton);


        verticalLayout->addLayout(ButtonArea);


        RightArea->addWidget(SendMessageWidget);

        RightArea->setStretch(1, 3);
        RightArea->setStretch(2, 1);

        horizontalLayout_4->addLayout(RightArea);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 4);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 725, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        UserLogo->setText(QString());
        UserName->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\346\230\265\347\247\260", nullptr));
        UserIdent->setText(QCoreApplication::translate("MainWindow", "#123456", nullptr));
        Address->setText(QCoreApplication::translate("MainWindow", "IP\345\234\260\345\235\200", nullptr));
        Port->setText(QCoreApplication::translate("MainWindow", "\347\253\257\345\217\243\345\217\267", nullptr));
        SearchEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\346\230\265\347\247\260/\347\224\250\346\210\267ID", nullptr));
        SearchButton->setText(QString());
        Title->setText(QCoreApplication::translate("MainWindow", "\345\261\200\345\237\237\347\275\221\350\201\212\345\244\251\345\256\244", nullptr));
        SendMessageEdit->setPlainText(QString());
        SendButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
