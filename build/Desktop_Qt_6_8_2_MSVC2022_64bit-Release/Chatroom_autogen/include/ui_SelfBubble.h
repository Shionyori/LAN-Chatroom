/********************************************************************************
** Form generated from reading UI file 'SelfBubble.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELFBUBBLE_H
#define UI_SELFBUBBLE_H

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

class Ui_SelfBubble
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *InfoArea;
    QHBoxLayout *UserInfoArea;
    QSpacerItem *UserSpacer;
    QLabel *UserName;
    QLabel *UserID;
    QHBoxLayout *MessageArea;
    QSpacerItem *MessageSpacer;
    QLabel *Message;
    QSpacerItem *BottomSpacer;
    QVBoxLayout *UserLogoArea;
    QPushButton *UserLogo;
    QSpacerItem *LogoSpacer;

    void setupUi(QWidget *SelfBubble)
    {
        if (SelfBubble->objectName().isEmpty())
            SelfBubble->setObjectName("SelfBubble");
        SelfBubble->resize(127, 108);
        horizontalLayout = new QHBoxLayout(SelfBubble);
        horizontalLayout->setObjectName("horizontalLayout");
        InfoArea = new QVBoxLayout();
        InfoArea->setSpacing(2);
        InfoArea->setObjectName("InfoArea");
        UserInfoArea = new QHBoxLayout();
        UserInfoArea->setSpacing(2);
        UserInfoArea->setObjectName("UserInfoArea");
        UserSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        UserInfoArea->addItem(UserSpacer);

        UserName = new QLabel(SelfBubble);
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

        UserID = new QLabel(SelfBubble);
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


        InfoArea->addLayout(UserInfoArea);

        MessageArea = new QHBoxLayout();
        MessageArea->setSpacing(4);
        MessageArea->setObjectName("MessageArea");
        MessageSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        MessageArea->addItem(MessageSpacer);

        Message = new QLabel(SelfBubble);
        Message->setObjectName("Message");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Message->sizePolicy().hasHeightForWidth());
        Message->setSizePolicy(sizePolicy);
        Message->setMinimumSize(QSize(20, 20));
        Message->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setKerning(true);
        Message->setFont(font2);
        Message->setStyleSheet(QString::fromUtf8("#Message\n"
"{\n"
"background-color:rgb(75, 224, 110);\n"
"border-radius:10px;\n"
"border-top-right-radius:0px;\n"
"padding:6px;\n"
"line-height:150%;\n"
"color:rgb(0, 0, 0);\n"
"}"));
        Message->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        MessageArea->addWidget(Message);


        InfoArea->addLayout(MessageArea);

        BottomSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        InfoArea->addItem(BottomSpacer);


        horizontalLayout->addLayout(InfoArea);

        UserLogoArea = new QVBoxLayout();
        UserLogoArea->setObjectName("UserLogoArea");
        UserLogo = new QPushButton(SelfBubble);
        UserLogo->setObjectName("UserLogo");
        UserLogo->setMinimumSize(QSize(35, 35));
        UserLogo->setMaximumSize(QSize(35, 35));
        UserLogo->setStyleSheet(QString::fromUtf8("#UserLogo{\n"
"background-color:rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:5px;\n"
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


        horizontalLayout->addLayout(UserLogoArea);


        retranslateUi(SelfBubble);

        QMetaObject::connectSlotsByName(SelfBubble);
    } // setupUi

    void retranslateUi(QWidget *SelfBubble)
    {
        SelfBubble->setWindowTitle(QCoreApplication::translate("SelfBubble", "Form", nullptr));
        UserName->setText(QCoreApplication::translate("SelfBubble", "\346\230\265\347\247\260", nullptr));
        UserID->setText(QCoreApplication::translate("SelfBubble", "#123456", nullptr));
        Message->setText(QCoreApplication::translate("SelfBubble", "\346\265\213\350\257\225\n"
"\346\265\213\350\257\225\n"
"\346\265\213\350\257\225", nullptr));
        UserLogo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SelfBubble: public Ui_SelfBubble {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELFBUBBLE_H
