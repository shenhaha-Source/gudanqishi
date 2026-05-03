#include"guanqiawindow.h"
#include<QPainter>
#include <QMouseEvent>
guanqiawindow::guanqiawindow(QDialog *parent) : QDialog(parent)
{
    this->setFixedSize(1600, 1000);
    this->setWindowTitle("关卡选择");
    btn1 = new QPushButton(this);
    btn1->setGeometry(120, 420, 400, 200);
    btn1->setStyleSheet("background: transparent; border: none;");
    btn2 = new QPushButton(this);
    btn2->setGeometry(600, 420, 400, 200);
    btn2->setStyleSheet("background: transparent; border: none;");
    btn3 = new QPushButton(this);
    btn3->setGeometry(1080, 420, 400, 200);
    btn3->setStyleSheet("background: transparent; border: none;");
    connect(btn1, &QPushButton::clicked, this, &guanqiawindow::choose1);
    connect(btn2, &QPushButton::clicked, this, &guanqiawindow::choose2);
    connect(btn3, &QPushButton::clicked, this, &guanqiawindow::choose3);
}
void guanqiawindow::choose1(){
    chosenlevel=1;
    emit showmainwindow();
    accept();
}
void guanqiawindow::choose2(){
    chosenlevel=2;
    emit showmainwindow();
     accept();
}
void guanqiawindow::choose3(){
    emit showmainwindow();
    chosenlevel=3;
    accept();
}
int guanqiawindow:: getChoosenguanqia() {
    return chosenlevel;
}
void guanqiawindow::setchosenlevel(int a){
    chosenlevel=a;
}
void guanqiawindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    QPixmap bgPix(":/gamewindow/guanqia.window.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), bgPix);
}
guanqiawindow::~guanqiawindow(){};