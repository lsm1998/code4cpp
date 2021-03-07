//
// Created by Administrator on 2021/3/7.
//

#include "subwidget.h"

Subwidget::Subwidget(QWidget *parent)
{
    this->setWindowTitle("子窗口");
    this->b.setParent(this);
    this->b.setText("切换到主窗口");
    this->b.move(50, 20);

    connect(&b, &QPushButton::clicked, this, &Subwidget::change);

    this->resize(400, 200);
}

void Subwidget::change()
{
    this->hide();
    emit mySignals();
}
