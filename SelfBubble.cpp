#include "SelfBubble.h"
#include "ui_SelfBubble.h"

SelfBubble::SelfBubble(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SelfBubble)
{
    ui->setupUi(this);
}

SelfBubble::~SelfBubble()
{
    delete ui;
}

void SelfBubble::setLogo(QIcon icon)
{
    ui->UserLogo->setIcon(icon);
}

void SelfBubble::setIdent(QString id)
{
    ui->UserID->setText(id);
}

void SelfBubble::setName(QString name)
{
    ui->UserName->setText(name);
}

void SelfBubble::setMessage(QString msg)
{
    const int maxWidth = 400;
    QFontMetrics fm(ui->Message->font());
    QString formattedMsg;
    QString line;
    int lineWidth = 0;
    for (int i = 0; i < msg.length(); ++i)
    {
        QChar ch = msg[i];
        int charWidth = fm.horizontalAdvance(ch);

        if (lineWidth + charWidth > maxWidth)
        {
            formattedMsg += line + "\n";
            line = ch;
            lineWidth = charWidth;
        }
        else
        {
            line += ch;
            lineWidth += charWidth;
        }
    }
    if (!line.isEmpty())
    {
        formattedMsg += line;
    }

    ui->Message->setText(formattedMsg);
    adjustSize();
}
