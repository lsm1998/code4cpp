//
// Created by Administrator on 2021/3/7.
//
#include <QApplication>
#include "mainwidget.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    MainWidget w;
    w.show();
    return QApplication::exec();
}
