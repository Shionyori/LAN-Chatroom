#ifndef MESSAGEBUBBLE_H
#define MESSAGEBUBBLE_H

#include <QWidget>

namespace Ui {
class MessageBubble;
}

class MessageBubble : public QWidget
{
    Q_OBJECT

public:
    explicit MessageBubble(QWidget *parent = nullptr);
    ~MessageBubble();

    //消息设置接口
    void setLogo(QIcon icon);
    void setIdent(QString id);
    void setName(QString name);
    void setMessage(QString msg);

private:
    Ui::MessageBubble *ui;
};

#endif // MESSAGEBUBBLE_H
