#include "OnlineUser.h"
#include "ui_OnlineUser.h"

OnlineUser::OnlineUser(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OnlineUser)
{
    ui->setupUi(this);
}

OnlineUser::~OnlineUser()
{
    delete ui;
}

void OnlineUser::setLogo(QIcon icon)
{
    ui->UserLogo->setIcon(icon);
}

void OnlineUser::setName(QString name)
{
    ui->UserName->setText(name);
}

void OnlineUser::setIdent(QString id)
{
    ui->UserID->setText(id);
}

void OnlineUser::setAddr(QString addr)
{
    ui->UserAddr->setText(addr);
}

void OnlineUser::setPort(QString port)
{
    ui->UserPort->setText(port);
}

QString OnlineUser::getIdent()
{
    return ui->UserID->text();
}

QString OnlineUser::getAddr()
{
    return ui->UserAddr->text();
}

QString OnlineUser::getPort()
{
    return ui->UserPort->text();
}

void OnlineUser::mousePressEvent(QMouseEvent *)
{
    qDebug() << "user clicked";
    emit clicked(ui->UserAddr->text(), ui->UserPort->text().toInt());
}

QString OnlineUser::getName()
{
    return ui->UserName->text();
}
