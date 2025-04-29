/********************************************************************************
** Form generated from reading UI file 'EmojiList.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMOJILIST_H
#define UI_EMOJILIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmojiList
{
public:

    void setupUi(QWidget *EmojiList)
    {
        if (EmojiList->objectName().isEmpty())
            EmojiList->setObjectName("EmojiList");
        EmojiList->resize(241, 221);

        retranslateUi(EmojiList);

        QMetaObject::connectSlotsByName(EmojiList);
    } // setupUi

    void retranslateUi(QWidget *EmojiList)
    {
        EmojiList->setWindowTitle(QCoreApplication::translate("EmojiList", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmojiList: public Ui_EmojiList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMOJILIST_H
