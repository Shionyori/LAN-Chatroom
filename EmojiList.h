#ifndef EMOJILIST_H
#define EMOJILIST_H

#include <QWidget>

namespace Ui {
class EmojiList;
}

class EmojiList : public QWidget
{
    Q_OBJECT

public:
    explicit EmojiList(QWidget *parent = nullptr);
    ~EmojiList();

signals:
    void emojiClicked(QString);

private:
    Ui::EmojiList *ui;

    void init();

public:
    QString emojis[30] = {"😃","😅","🤣","😉","😘","😊",
                          "😋","🤗","🤔","😐","😎","😰",
                          "😭","😱","😓","😡","😈","🤡",
                          "💔","💖","🧐","🤨","😪","😇"};
};

#endif // EMOJILIST_H
