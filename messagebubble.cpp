#include "messagebubble.h"
#include "ui_messagebubble.h"

MessageBubble::MessageBubble(QWidget *parent)
    : QWidget(parent), ui(new Ui::MessageBubble)
{
    ui->setupUi(this);
}

MessageBubble::~MessageBubble()
{
    delete ui;
}

void MessageBubble::setLogo(QIcon icon)
{
    ui->UserLogo->setIcon(icon);
}

void MessageBubble::setIdent(QString id)
{
    ui->UserID->setText(id);
}

void MessageBubble::setName(QString name)
{
    ui->UserName->setText(name);
}

void MessageBubble::setMessage(QString msg)
{
    // const int lineLength = 35;
    // QString formattedMsg;
    // for (int i = 0; i < msg.length(); i += lineLength) {
    //     QString line = msg.mid(i, lineLength);
    //     formattedMsg += line;
    //     if (i + lineLength < msg.length()) {
    //         formattedMsg += "\n";
    //     }
    // }

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
