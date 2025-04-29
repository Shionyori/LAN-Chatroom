/********************************************************************************
** Form generated from reading UI file 'messagebubble.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEBUBBLE_H
#define UI_MESSAGEBUBBLE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessageBubble
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *UserLogoArea;
    QPushButton *UserLogo;
    QSpacerItem *LogoSpacer;
    QVBoxLayout *InfoArea;
    QHBoxLayout *UserInfoArea;
    QLabel *UserName;
    QLabel *UserID;
    QSpacerItem *UserSpacer;
    QHBoxLayout *MessageArea;
    QLabel *Message;
    QSpacerItem *MessageSpacer;
    QSpacerItem *BottomSpacer;

    void setupUi(QWidget *MessageBubble)
    {
        if (MessageBubble->objectName().isEmpty())
            MessageBubble->setObjectName("MessageBubble");
        MessageBubble->resize(111, 89);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MessageBubble->sizePolicy().hasHeightForWidth());
        MessageBubble->setSizePolicy(sizePolicy);
        MessageBubble->setMinimumSize(QSize(100, 50));
        MessageBubble->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_2 = new QHBoxLayout(MessageBubble);
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(4, 4, 4, 6);
        UserLogoArea = new QVBoxLayout();
        UserLogoArea->setObjectName("UserLogoArea");
        UserLogo = new QPushButton(MessageBubble);
        UserLogo->setObjectName("UserLogo");
        UserLogo->setMinimumSize(QSize(35, 35));
        UserLogo->setMaximumSize(QSize(35, 35));
        UserLogo->setStyleSheet(QString::fromUtf8("#UserLogo{\n"
"background-color:rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius: 5px;\n"
"}\n"
"#UserLogo:hover{\n"
"background-color:#c0c0c0;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/resource/user.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        UserLogo->setIcon(icon);
        UserLogo->setIconSize(QSize(30, 30));

        UserLogoArea->addWidget(UserLogo);

        LogoSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        UserLogoArea->addItem(LogoSpacer);


        horizontalLayout_2->addLayout(UserLogoArea);

        InfoArea = new QVBoxLayout();
        InfoArea->setSpacing(2);
        InfoArea->setObjectName("InfoArea");
        UserInfoArea = new QHBoxLayout();
        UserInfoArea->setSpacing(2);
        UserInfoArea->setObjectName("UserInfoArea");
        UserName = new QLabel(MessageBubble);
        UserName->setObjectName("UserName");
        UserName->setMinimumSize(QSize(20, 20));
        UserName->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        UserName->setFont(font);
        UserName->setStyleSheet(QString::fromUtf8("#UserName{\n"
"color:rgb(0, 0, 0)\n"
"}"));

        UserInfoArea->addWidget(UserName);

        UserID = new QLabel(MessageBubble);
        UserID->setObjectName("UserID");
        UserID->setMinimumSize(QSize(20, 20));
        UserID->setMaximumSize(QSize(16777215, 20));
        QFont font1;
        font1.setPointSize(8);
        UserID->setFont(font1);
        UserID->setStyleSheet(QString::fromUtf8("#UserID{\n"
"color:rgb(0, 0, 0)\n"
"}"));

        UserInfoArea->addWidget(UserID);

        UserSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        UserInfoArea->addItem(UserSpacer);


        InfoArea->addLayout(UserInfoArea);

        MessageArea = new QHBoxLayout();
        MessageArea->setSpacing(4);
        MessageArea->setObjectName("MessageArea");
        Message = new QLabel(MessageBubble);
        Message->setObjectName("Message");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Message->sizePolicy().hasHeightForWidth());
        Message->setSizePolicy(sizePolicy1);
        Message->setMinimumSize(QSize(20, 20));
        Message->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setKerning(true);
        Message->setFont(font2);
        Message->setStyleSheet(QString::fromUtf8("#Message\n"
"{\n"
"background-color:rgb(222, 222, 222);\n"
"border-radius:10px;\n"
"border-top-left-radius:0px;\n"
"padding:6px;\n"
"line-height:150%;\n"
"color:rgb(0, 0, 0);\n"
"}"));
        Message->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        MessageArea->addWidget(Message);

        MessageSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        MessageArea->addItem(MessageSpacer);


        InfoArea->addLayout(MessageArea);

        BottomSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        InfoArea->addItem(BottomSpacer);


        horizontalLayout_2->addLayout(InfoArea);


        retranslateUi(MessageBubble);

        QMetaObject::connectSlotsByName(MessageBubble);
    } // setupUi

    void retranslateUi(QWidget *MessageBubble)
    {
        MessageBubble->setWindowTitle(QCoreApplication::translate("MessageBubble", "Form", nullptr));
        UserLogo->setText(QString());
        UserName->setText(QCoreApplication::translate("MessageBubble", "\346\230\265\347\247\260", nullptr));
        UserID->setText(QCoreApplication::translate("MessageBubble", "#123456", nullptr));
        Message->setText(QCoreApplication::translate("MessageBubble", "\346\265\213\350\257\225\n"
"\346\265\213\350\257\225\n"
"\346\265\213\350\257\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessageBubble: public Ui_MessageBubble {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEBUBBLE_H
