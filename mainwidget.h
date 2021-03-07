//
// Created by Administrator on 2021/3/7.
//

#ifndef CODE4CPP_MAINWIDGET_H
#define CODE4CPP_MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h"

class MainWidget : public QWidget
{
Q_OBJECT

public:
    MainWidget();

    ~MainWidget();
private:
    QPushButton *b1;
    QPushButton *b2;
    QPushButton *b3;

    Subwidget subwidget;

    void click();

    void change();

    void dealSub();
};

#endif //CODE4CPP_MAINWIDGET_H
