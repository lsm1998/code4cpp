//
// Created by Administrator on 2021/3/7.
//
#include "mainwidget.h"

MainWidget::MainWidget()
        : QWidget(nullptr)
{
    this->setWindowTitle("主窗口");
    this->b1 = new QPushButton(this);
    this->b2 = new QPushButton(this);
    this->b3 = new QPushButton(this);

    b1->setText("确定");
    b2->setText("退出");
    b3->setText("切换");

    b1->move(80, 100);
    b2->move(180, 100);
    b3->move(280, 100);

    b1->show();
    b2->show();
    b3->show();

    connect(b2, &QPushButton::pressed, this, &MainWidget::close);

    connect(b1, &QPushButton::released, this, &MainWidget::click);

    connect(b3, &QPushButton::released, this, &MainWidget::change);

    // 子窗口的信号
    connect(&subwidget, &Subwidget::mySignals, this, &MainWidget::dealSub);

    this->resize(420, 200);
}

MainWidget::~MainWidget()
{
}

void MainWidget::click()
{
    QString text = b1->text();
    if (text.length() > 10)
    {
        b1->setText("确定");
    } else
    {
        b1->setText(text + "123 ");
    }
}

void MainWidget::change()
{
    this->subwidget.show();
    this->hide();
}

void MainWidget::dealSub()
{
    this->show();
}
