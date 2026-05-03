#include "bullet.h"
#include <QPainter>
bullet::bullet(int sx, int sy, double dx, double dy,int type)
    : x(sx), y(sy), dx(dx), dy(dy),
    speed(12), active(true),mytype(type)
{
    if(mytype==1){
        pix.load(":/bullte/bullute11.png");
        speed=12;
    }
    if(mytype==2){
        pix.load(":/bullte/bulltue3 (2).png");
        speed=12;
    }
    if(mytype==3){pix.load(":/bullte/bullte2(1).png");
        speed=10;
    }
    if(mytype==4){
        pix.load(":/bullte/bullte2(1).png");
        speed=12;
    }
    if(mytype==5){
        pix.load(":/bullte/bulltue3.png");
        speed=12;
    }
}
void bullet::update()
{
    if (!active) return;
    x += dx * speed;
    y += dy * speed;
    if (x < 0 || x > 1600 || y < 0 || y >1600)
        active = false;
}

void bullet::draw(QPainter* p)
{
    if (active)
        p->drawPixmap(x, y, pix);
}

QRect bullet::rect()
{
    return QRect(x, y, pix.width(), pix.height());
}

bool bullet::isactive()
{
    return active;
}

void bullet::setinactive()
{
    active = false;
}
int  bullet::gettype(){
    return mytype;
}
bullet::~bullet(){}