#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "messagebubble.h"

#include <QDialog>
#include <QFileDialog>
#include <QLabel>
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , socket(new QUdpSocket(this)) //[Debug2025/4/19]忘记在构造函数中对socket初始化而导致运行错误
{
    ui->setupUi(this);

    netWorkInit();
    guiInit();
}

MainWindow::~MainWindow()
{
    socket->close();
    delete ui;
}

//发送数据报
void MainWindow::sendMessage(netData data, QHostAddress addr, int port)
{
    socket->writeDatagram((char*)&data, sizeof(data), addr, port);
    addMessageBubble(data.id, data.name, data.buffer);
}

//添加聊天气泡
void MainWindow::addMessageBubble(QString ident, QString name, QString msg)
{
    QListWidgetItem *item = new QListWidgetItem(ui->RecvMessageWidget);
    MessageBubble *bubble = new MessageBubble(ui->RecvMessageWidget);

    bubble->setIdent(ident);
    bubble->setName(name);
    bubble->setMessage(msg);
    bubble->adjustSize(); //调整气泡大小
    item->setSizeHint(bubble->size()); //根据气泡大小再调整控件大小

    ui->RecvMessageWidget->addItem(item);
    ui->RecvMessageWidget->setItemWidget(item, bubble);

    ui->RecvMessageWidget->scrollToBottom();
}

//初始化网络连接（绑定+套接字设置+连接信号与槽函数）
void MainWindow::netWorkInit()
{
    socket = new QUdpSocket(this);

    //绑定到地址
    quint16 port = 7788;
    while(port <= 65535)
    {
        if(socket->bind(QHostAddress::AnyIPv4,port))break;
        port++;
    }

    // if(!socket->bind(QHostAddress::AnyIPv4, 8900))
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

    QHostAddress addr = socket->localAddress();
    qDebug() << addr;
}

//接受数据包
void MainWindow::recvMessage()
{
    netData data;
    QHostAddress addr;
    quint16 port;
    socket->readDatagram((char*)&data, sizeof(data), &addr, &port); //从UDP socket中读取一个数据报（Datagram），将其内容，以及发送方的地址和端口一并存入data变量中
    qDebug() << "来自:" << addr << "端口:" << port << "消息:" << data.buffer;

    addMessageBubble(data.id, data.name, data.buffer);
}

//发送按钮
void MainWindow::on_SendButton_clicked()
{
    QString msg = ui->SendMessageEdit->toPlainText();
    qDebug() << msg;

    //把要发送的文本内容打包为一个data实例
    netData data;
    qstrcpy(data.id, ui->UserIdent->text().toStdString().c_str());
    qstrcpy(data.name, ui->UserName->text().toStdString().c_str());
    qstrcpy(data.buffer, msg.toStdString().c_str());

    sendMessage(data, QHostAddress::Broadcast, 8900);

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

