#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) // argc命令行参数数量 argv命令内容
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec(); //（QApplication）启用事件循环，监听用户输入
}
