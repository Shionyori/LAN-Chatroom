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

// 璁剧疆姘旀场娑堟伅鍐呭
void MessageBubble::setMessage(QString msg)
{
    // const int lineLength = 35; //姣忚鏄剧ず鐨勫瓧绗︽暟
    // QString formattedMsg;
    // for (int i = 0; i < msg.length(); i += lineLength) {
    //     QString line = msg.mid(i, lineLength);
    //     formattedMsg += line;
    //     if (i + lineLength < msg.length()) { //濡傛灉涓嶆槸鏈€鍚庝竴琛岋紝娣诲姞鎹㈣绗�
    //         formattedMsg += "\n";
    //     }
    // }

    const int maxWidth = 400;             // 鍋囪鏈€澶у搴︿负 400 鍍忕礌
    QFontMetrics fm(ui->Message->font()); // 鑾峰彇褰撳墠瀛椾綋鐨勫害閲忎俊鎭�
    QString formattedMsg;
    QString line;
    int lineWidth = 0;
    for (int i = 0; i < msg.length(); ++i)
    {
        QChar ch = msg[i];
        int charWidth = fm.horizontalAdvance(ch); // 鑾峰彇褰撳墠瀛楃鐨勫搴�

        if (lineWidth + charWidth > maxWidth)
        {
            formattedMsg += line + "\n"; // 娣诲姞褰撳墠琛屽苟鎹㈣
            line = ch;                   // 褰撳墠琛岄噸缃负褰撳墠瀛楃
            lineWidth = charWidth;       // 褰撳墠琛屽搴﹂噸缃负褰撳墠瀛楃瀹藉害
        }
        else
        {
            line += ch;             // 灏嗗綋鍓嶅瓧绗︽坊鍔犲埌褰撳墠琛�
            lineWidth += charWidth; // 鏇存柊褰撳墠琛屽搴�
        }
    }
    if (!line.isEmpty())
    {
        formattedMsg += line;
    }

    ui->Message->setText(formattedMsg);
    adjustSize();
}
