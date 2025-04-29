#include "EmojiList.h"
#include "ui_EmojiList.h"

#include <QGridLayout>
#include <qpushbutton.h>

EmojiList::EmojiList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EmojiList)
{
    ui->setupUi(this);
    init();
}

EmojiList::~EmojiList()
{
    delete ui;
}

void EmojiList::init()
{
    QGridLayout *central = new QGridLayout(this);
    central->setSpacing(2);
    central->setContentsMargins(10,10,10,10);

    for(int column = 0; column < 6; column++)
    {
        for(int row = 0; row < 4; row++)
        {
            QPushButton *emoji = new QPushButton(this);
            emoji->setFixedSize(40,40);
            emoji->setText(emojis[column + row * 6]);

            //设置字体大小或样式
            // QFont font = emoji->font();
            // font.setPointSize(15);
            // emoji->setFont(font);

            emoji->setStyleSheet("QPushButton{font-size: 16pt;} "
                                 "QPushButton:hover{"
                                 "border:none; "
                                 "border-radius:5px; "
                                 "background-color:#c0c0c0;}"); //设置样式表

            central->addWidget(emoji, row, column);
            connect(emoji, &QPushButton::clicked, this, [=](){
                emit emojiClicked(emoji->text());
            });
        }
    }

    this->adjustSize();
}
