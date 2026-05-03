#include"monster.h"
monster::monster(int a){
    hit_points=19;
    speed=4;
    x=0;
    y=0;
    attack=1;
    dy=0,dx=0;
    intial(a);
    type=a;
    r1=500;
    r2=500;
    randomdirection();
}
void monster::intial(int a){
    if(a==1){
        image.load(":/monster/monster1.png");
        hit_points=10;
    }
    else if(a==2){
        image.load(":/monster/monster2.png");
        hit_points=12;
    }
    else if(a==3){
        image.load(":/monster/monster3.png");
        hit_points=50;
    }
    else if(a==4){
        image.load(":/monster/monster5.png");
        hit_points=25;
    }
    else{
        image.load(":/monster/boss(1).png");
        hit_points=240;
    }
}
QRect monster::rect() const{
      return QRect(x, y, image.width(), image.height());
}
void monster::setsudu(double dx,double dy){
    this->dx=dx;
    this->dy=dy;
}
int  monster::getheigth(){
    return image.height();
}
int monster:: getwidth(){
    return image.width();
}
void monster::setpoints(int a,int b){
    bornx=a;
    borny=b;
    this->x=a;
    this->y=b;
}
void monster::settarget(int x,int y){
    targetpoint.rx()=x;
    targetpoint.ry()=y;
}
int monster:: gethit_points(){
    return hit_points;
}
int monster::gettype(){
    return type;
}
int monster::getattacK(){
    return attack;
}
int monster::getX(){
    return x;
}
int monster::getY(){
    return y;
}
int monster::getspeed(){
    return speed;
}
void monster::setX(int x){
    this->x=x;
}
void monster::setY(int y){
    this->y=y;
}
void monster::sethit_points(int x){
    hit_points=x;
}
void monster::setattack(int x){
    attack=x;
}
void monster::setspeed(int a){
    speed=a;
}
void monster::darw(QPainter &p){
p.drawPixmap(x, y, image);
}
int  monster::getr1(){
    return r1;
}
int monster::getr2(){
    return r2;
}
void monster::randomdirection()
{
    double angle = (rand() % 360) * 3.14159 / 180.0;
    dx = speed*cos(angle);
    dy = speed*sin(angle);
}
void monster::takedamage(int val){
    hit_points-=val;
}
bool monster::isdead() const{
    return hit_points<=0;
}
void monster::update(){
        // 朝骑士方向移动
    double speed = 6.0; // 基础速度
    if(type == 2) speed = 6.5;
    if(type == 3) speed = 4.5;

    double dx_born = x - bornx;
    double dy_born = y - borny;
    double dist_born = sqrt(dx_born*dx_born + dy_born*dy_born);

    // 到玩家距离
    double dx_player = targetpoint.x() - x;
    double dy_player = targetpoint.y() - y;
    double dist_player = sqrt(dx_player*dx_player + dy_player*dy_player);
    //行为逻辑
    if (dist_player < r1) {

        dx = speed*dx_player / dist_player;
        dy = speed*dy_player / dist_player;

    } else {
        if (dist_born < r2) {
            // 范围内：随机逛
            if (rand() % 150 == 0)
                randomdirection();
        } else {
            // 超出范围：走回去
            dx = -speed*dx_born / dist_born;
            dy = -speed*dy_born / dist_born;
        }}
        // 位置更新
        x += dx;
        y += dy;
        // 边界反弹
        int w = image.width();
        int h = image.height();
        if(x < 0 ||x + w > 1400) dx = -dx;
        if(y < 0 ||y + h > 1600) dy = -dy;
    }
monster::~monster(){}

