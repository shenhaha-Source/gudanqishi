#include"jimonster.h"
jimonster::jimonster(int a){
    hit_points=3;
    speed=12;
    x=0;
    y=0;
    attack=1;
    dy=0,dx=0;
    intial(a);
}
void jimonster::intial(int a){
    if(a==1){
        image.load(":/monster/tujibing1(1)(1).png");
    }
    else if(a==2){
        image.load(":/monster/monster2.png");
    }
    else if(a==3){
        image.load(":/monster/monster3.png");
    }
    else if(a==4){
        image.load(":/monster/monster5.png");
    }
    else{
        image.load(":/qishi/7.png");
    }
}
QRect jimonster::rect() const{
    return QRect(x, y, image.width(), image.height());
}
void jimonster::setsudu(double dx,double dy){
    this->dx=dx;
    this->dy=dy;
}
int  jimonster::getheigth(){
    return image.height();
}
int jimonster:: getwidth(){
    return image.width();
}
void jimonster::setpoints(int a,int b){
    this->x=a;
    this->y=b;
}
void jimonster::settarget(int x,int y){
    targetpoint.rx()=x;
    targetpoint.ry()=y;
}
int jimonster:: gethit_points(){
    return hit_points;
}
int jimonster::gettype(){
    return type;
}
int jimonster::getattacK(){
    return attack;
}
int jimonster::getX(){
    return x;
}
int jimonster::getY(){
    return y;
}
int jimonster::getspeed(){
    return speed;
}
void jimonster::setX(int x){
    this->x=x;
}
void jimonster::setY(int y){
    this->y=y;
}
void jimonster::sethit_points(int x){
    hit_points=x;
}
void jimonster::setattack(int x){
    attack=x;
}
void jimonster::setspeed(int a){
    speed=a;
}
void jimonster::darw(QPainter &p){
    p.drawPixmap(x, y, image);
}

void jimonster::update(){
    // 朝骑士方向移动
    double speed = 9.0; // 基础速度
    if(type == 2) speed = 3.5;
    if(type == 3) speed = 4.5;
    int dx = targetpoint.rx() - x;
    int dy =  targetpoint.ry()- y;
    double len = hypot(dx, dy) + 0.1;
    // 位置更新
    x += dx / len * speed;
    y += dy / len * speed;
    // 边界反弹
    int w = image.width();
    int h = image.height();
    if(x < 0 ||x + w > 1400) dx = -dx;
    if(y < 0 ||y + h > 1600) dy = -dy;
}
jimonster::~jimonster(){}
