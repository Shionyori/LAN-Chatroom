#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "messagebubble.h"
#include "OnlineUser.h"
#include "SelfBubble.h"
#include "EmojiList.h"

#include <QDialog>
#include <QFileDialog>
#include <QLabel>
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , socket(new QUdpSocket(this)) //[Debug2025/4/19]忘记在构造函数中对socket初始化而导致运行错误
    , IsUserChat(false)
{
    ui->setupUi(this);

    netWorkInit();
    guiInit();

    //发送上线消息
    sendSignal(true);
}

MainWindow::~MainWindow()
{
    sendSignal(false);

    socket->close();
    delete ui;
}

//发送数据报
void MainWindow::sendMessage(netData data, QHostAddress addr, int port)
{
    socket->writeDatagram((char*)&data, sizeof(data), addr, port);
}

//添加聊天气泡
void MainWindow::addMessageBubble(QString ident, QString name, QString msg)
{
    QListWidgetItem *item = new QListWidgetItem(IsUserChat? ui->UserMessageWidget : ui->RecvMessageWidget);
    MessageBubble *bubble = new MessageBubble(IsUserChat? ui->UserMessageWidget : ui->RecvMessageWidget);

    bubble->setIdent(ident);
    bubble->setName(name);
    bubble->setMessage(msg);
    bubble->adjustSize(); //调整气泡大小
    item->setSizeHint(bubble->size()); //根据气泡大小再调整控件大小

    if(IsUserChat)
    {
        ui->UserMessageWidget->addItem(item);
        ui->UserMessageWidget->setItemWidget(item, bubble);
        ui->UserMessageWidget->scrollToBottom();
    }
    else
    {
        ui->RecvMessageWidget->addItem(item);
        ui->RecvMessageWidget->setItemWidget(item, bubble);
        ui->UserMessageWidget->scrollToBottom();
    }

}

//添加自己的聊天气泡
void MainWindow::addSelfBubble(QString ident, QString name, QString msg)
{
    QListWidgetItem *item = new QListWidgetItem(IsUserChat? ui->UserMessageWidget : ui->RecvMessageWidget);
    SelfBubble *bubble = new SelfBubble(IsUserChat? ui->UserMessageWidget : ui->RecvMessageWidget);

    bubble->setIdent(ident);
    bubble->setName(name);
    bubble->setMessage(msg);
    bubble->adjustSize(); //调整气泡大小
    item->setSizeHint(bubble->size()); //根据气泡大小再调整控件大小

    if(IsUserChat)
    {
        ui->UserMessageWidget->addItem(item);
        ui->UserMessageWidget->setItemWidget(item, bubble);
        ui->UserMessageWidget->scrollToBottom();
    }
    else
    {
        ui->RecvMessageWidget->addItem(item);
        ui->RecvMessageWidget->setItemWidget(item, bubble);
        ui->RecvMessageWidget->scrollToBottom();
    }


}

//添加上线用户列表(并连接用户点击事件的信号与槽)
void MainWindow::addOnlineUser(QString name, QString id, QString addr, QString port)
{   
    QListWidgetItem *item = new QListWidgetItem(ui->OnlineListWidget);

    item->setData(NAME, name);
    item->setData(ID, id);
    item->setData(ADDR, addr);
    item->setData(PORT, port);

    OnlineUser *user = new OnlineUser(ui->OnlineListWidget);

    //设置子控件（item）的样式表才能改变条目样式
    ui->OnlineListWidget->setStyleSheet("#OnlineListWidget{"
                                        "border: 1px solid #c0c0c0;"
                                        "border-radius:5px;"
                                        "background-color:rgb(255,255,255);"
                                        "}"
                                        "QListWidget::item {"
                                        "background-color: rgb(255, 255, 255);"
                                        "border: none;"
                                        "margin: 0;"
                                        "padding: 0;"
                                        "}"
                                        "QListWidget::item:hover {"
                                        "background-color: #c0c0c0;"
                                        "}");

    bool is_connect = connect(user, &OnlineUser::clicked, this, [=](QString addr, quint16 port){
        ui->RecvMessageArea->setCurrentIndex(1); //切换到用户聊天窗口（*暂未完善，后续需要添加多个用户窗口才行*）
        IsUserChat = true;
        current_user_addr = addr;
        current_user_port = port;
    });
    qDebug() << "connect:" << is_connect;

    item->setSizeHint(user->size());
    user->setName(name);
    user->setIdent(id);
    user->setAddr(addr);
    user->setPort(port);
    ui->OnlineListWidget->insertItem(ui->OnlineListWidget->count(), item);
    ui->OnlineListWidget->setItemWidget(item, user);
}

//删除上线用户列表
void MainWindow::delOnlineUser(QString name, QString id, QString addr, QString port)
{
    int count = ui->OnlineListWidget->count();
    for(int i = 0; i < count; i++)
    {
        QListWidgetItem *item = ui->OnlineListWidget->item(i); //获取条目
        OnlineUser *user = static_cast<OnlineUser*>(ui->OnlineListWidget->itemWidget(item)); //控件强转为OnlineUser对象
        if(name == user->getName() &&
            id == user->getIdent() &&
            addr == user->getAddr() &&
            port == user->getPort())
        {
            ui->OnlineListWidget->removeItemWidget(item); //移除该条目（item）下的控件（widget）
            ui->OnlineListWidget->takeItem(i); //移除条目（item）
            user->deleteLater();
        }
    }
}

//初始化网络连接（绑定+套接字设置+连接信号与槽函数）
void MainWindow::netWorkInit()
{
    socket = new QUdpSocket(this);

    //绑定到地址
    quint16 port = 8899;
    while(port <= 65535)
    {
        if(socket->bind(QHostAddress::AnyIPv4,port))break;
        port++;
    }

    // if(!socket->bind(QHostAddress::AnyIPv4, 8899)) //[DEBUG2025/4/24]端口号前后设置不一致导致消息无法正常交换
    // {
    //     QDialog log;
    //     log.resize(200,110);
    //     log.setWindowTitle("错误警告");
    //     QLabel label(&log);
    //     label.setGeometry(0, 0, log.width(), log.height());
    //     label.setText("端口被占用！");
    //     log.exec();
    //     return;
    // }

    //打开套接字读写
    socket->open(QIODevice::ReadWrite);
    //设置广播
    socket->joinMulticastGroup(QHostAddress::Broadcast);
    //关联可读信号和槽函数
    connect(socket, &QUdpSocket::readyRead, this, &MainWindow::recvMessage);
}

//加载用户信息
void MainWindow::guiInit()
{
    QString MachineName = QSysInfo::machineHostName();
    QString ProductName = QSysInfo::prettyProductName();
    QString bootId = QSysInfo::machineUniqueId();

    uint ident = qHash(MachineName+ProductName+bootId) % 100000000;
    qDebug() << ident;

    ui->UserIdent->setText(QString::number(ident));
    ui->UserName->setText(MachineName);

    QHostAddress addr = socket->localAddress(); //因为使用的是UDP所以套接字并没有特定的绑定对象，addr返回值为0.0.0.0
    qDebug() << addr;
    int port = socket->localPort();
    ui->Address->setText(addr.toString());
    ui->Port->setText(QString::number(port));
}

//通知其他用户该用户已上线
void MainWindow::sendSignal(bool status)
{
    netData data;
    qstrcpy(data.id, ui->UserIdent->text().toStdString().c_str());
    qstrcpy(data.name, ui->UserName->text().toStdString().c_str());
    if(status)
    {
        qstrcpy(data.buffer, "{[<-ONLINE->]}");
    }
    else
    {
        qstrcpy(data.buffer, "{[<-OFFLINE->]}");
    }
    sendMessage(data, QHostAddress::Broadcast, 8899);
}

//判断是否在用户列表中
bool MainWindow::isOnOnlineList(netData data, QHostAddress addr, quint16 port)
{
    if(ui->OnlineListWidget->count() == 0) return false;
    for(int i = 0; i < ui->OnlineListWidget->count(); i++)
    {
        QListWidgetItem *item = ui->OnlineListWidget->item(i);
        //判断是否在列表中
        if(/*item->data(ID).toString() == data.id &&*/ //[DEBUG2025/5/3] *暂未解决* 由于不明原因导致ID的数据是端口号
            item->data(NAME).toString() == data.name &&
            item->data(PORT).toInt() == port)
        {
            return true;
        }
    }
    return false;
}

//接受数据报
void MainWindow::recvMessage()
{
    netData data;
    QHostAddress addr;
    quint16 port;
    socket->readDatagram((char*)&data, sizeof(data), &addr, &port); //从UDP socket中读取一个数据报（Datagram），将其内容，以及发送方的地址和端口一并存入data变量中
    qDebug() << "来自:" << addr << "端口:" << port << "消息:" << data.buffer;

    //过滤自己的消息
    if(data.id == ui->UserIdent->text() && port == socket->localPort()) return;

    //判断消息种类
    if(data.buffer == QString("{[<-ONLINE->]}"))
    {
        //判断是否在列表中
        qDebug() << "in the list:" << isOnOnlineList(data, addr, port);
        if(!isOnOnlineList(data, addr, port))
        {
            netData sigdata;
            qstrcpy(sigdata.id, ui->UserIdent->text().toStdString().c_str());
            qstrcpy(sigdata.name, ui->UserName->text().toStdString().c_str());
            qstrcpy(sigdata.buffer, "{[<-ONLINE->]}");
            sendMessage(sigdata, addr, port);
            addOnlineUser(data.name, data.id, addr.toString(), QString::number(port));
        }
    }
    else if(data.buffer == QString("{[<-OFFLINE->]}"))
    {
        delOnlineUser(data.name,data.id, addr.toString(), QString::number(port));
    }
    else
    {
        addMessageBubble(data.id, data.name, data.buffer);
    }
}

//发送按钮
void MainWindow::on_SendButton_clicked()
{
    //把要发送的文本内容打包为一个data实例
    netData data;
    qstrcpy(data.id, ui->UserIdent->text().toStdString().c_str());
    qstrcpy(data.name, ui->UserName->text().toStdString().c_str());
    qstrcpy(data.buffer, ui->SendMessageEdit->toPlainText().toStdString().c_str());

    //判断是用户聊天还是广播聊天
    if(IsUserChat)
    {
        sendMessage(data, QHostAddress(current_user_addr), current_user_port);
        addSelfBubble(data.id, data.name, data.buffer);
    }
    else
    {
        sendMessage(data, QHostAddress::Broadcast, 8899);
        addSelfBubble(data.id, data.name, data.buffer);
    }

    ui->SendMessageEdit->clear();
}

//头像按钮
void MainWindow::on_UserLogo_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("选择头像文件"), "./", "Image(*.png *.jpg)");
    if(!path.isEmpty())
    {
        ui->UserLogo->setIcon(QIcon(path));
    }
}

//搜索框检测
void MainWindow::on_SearchEdit_textChanged(const QString &arg1)
{
    for(int i = 0; i < ui->OnlineListWidget->count(); i++)
    {
        QListWidgetItem *item = ui->OnlineListWidget->item(i);
        if(item->data(ID).toString() == arg1 ||
            item->data(NAME).toString() == arg1 ||
            item->data(ADDR).toString() == arg1 ||
            item->data(PORT).toString() == arg1 ||
            arg1 == "")
        {
            item->setHidden(false);
        }
        else
        {
            item->setHidden(true);
        }
    }
}

//表情按钮
void MainWindow::on_EmojiButton_clicked()
{
    QPoint point = ui->SendMessageWidget->pos();
    EmojiList *emojiList = new EmojiList(this);
    point.setY(point.y() - emojiList->height());
    emojiList->move(point);
    emojiList->show();

    connect(emojiList, &EmojiList::emojiClicked, this, [=](QString emoji){
        ui->SendMessageEdit->insertPlainText(emoji);
        emojiList->deleteLater();
    });
}


