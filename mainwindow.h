#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum itemData
    {
        ID,
        NAME,
        ADDR,
        PORT,
    };
    struct netData
    {
        netData() : id(""), name(""), buffer("") {}
        char id[10];
        char name[20];
        char buffer[2048];
    };

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //发送自定义数据的接口
    void sendMessage(netData data, QHostAddress addr, int port);
    void addMessageBubble(QString ident, QString name, QString msg);
    void addSelfBubble(QString ident, QString name, QString msg);
    void addOnlineUser(QString name, QString id, QString addr, QString port);
    void delOnlineUser(QString name, QString id, QString addr, QString port);

protected:
    //初始化网络
    void netWorkInit();
    void guiInit();
    void sendSignal(bool status);


public slots:
    //接受数据
    void recvMessage();

private slots:
    void on_SendButton_clicked();

    void on_UserLogo_clicked();

    void on_SearchEdit_textChanged(const QString &arg1);

    void on_EmojiButton_clicked();

private:
    Ui::MainWindow *ui;
    QUdpSocket *socket;
};
#endif // MAINWINDOW_H
