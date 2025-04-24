#ifndef ONLINEUSER_H
#define ONLINEUSER_H

#include <QWidget>

namespace Ui {
class OnlineUser;
}

class OnlineUser : public QWidget
{
    Q_OBJECT

public:
    explicit OnlineUser(QWidget *parent = nullptr);
    ~OnlineUser();

    void setLogo(QIcon icon);
    void setName(QString name);
    void setIdent(QString id);
    void setAddr(QString addr);
    void setPort(QString port);

private:
    Ui::OnlineUser *ui;
};

#endif // ONLINEUSER_H
