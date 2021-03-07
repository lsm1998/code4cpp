//
// Created by Administrator on 2021/3/7.
//

#ifndef CODE4CPP_SUBWIDGET_H
#define CODE4CPP_SUBWIDGET_H

#include <QWidget>
#include <QPushButton>

class Subwidget : public QWidget
{
Q_OBJECT
public:
    explicit Subwidget(QWidget *parent = nullptr);

signals:
    void mySignals();

public slots:
private:
    QPushButton b;

    void change();
};


#endif //CODE4CPP_SUBWIDGET_H
