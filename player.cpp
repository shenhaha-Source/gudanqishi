#include"player.h"
player::player(){
    hit_points=15;
     barrier=5;
     speed=12;
     attack=2;
     x=100;
     y=100;
     image.load(":/qishi/2.png");
     walk1.load(":/qishi/3.png");
     walk2.load(":/qishi/4.png");
     walk3.load(":/qishi/5.png");
     walk4.load(":/qishi/6.png");
     walk5.load(":/qishi/7.png");
     walk6.load(":/qishi/8.png");
     walk7.load(":/qishi/9.png");
     walk8.load(":/qishi/10.png");
     walkindex=-1;
     walktimer=0;
     isrightmove=false;
     isleftmove=false;
     stopright=true;
     stopleft=false;
}
void player::sethit_points(int a){
    hit_points-=a;
    if(hit_points<=0){
        hit_points=0;
    }
}
void player::moveup(){
    y-=speed;
}
void player::movedown(){
    y+=speed;
}
void player::moveleft(){
    x-=speed;
}
void player::moveright(){
    x+=speed;
}
void player::draw(QPainter & p){
        if (walkindex == -1) {
        if(stopleft==true){
            p.drawPixmap(x, y, walk8);
        }
        if(stopright==true){
            p.drawPixmap(x, y, image);
        }
        }
        else {
            if(isrightmove){
            switch (walkindex) {
            case 0: p.drawPixmap(x, y, walk1); break;
            case 1: p.drawPixmap(x, y, walk2); break;
            case 2: p.drawPixmap(x, y, walk3); break;
            case 3: p.drawPixmap(x, y, walk4); break;
            }}
            if(isleftmove){
                switch (walkindex) {
                case 0: p.drawPixmap(x, y, walk5); break;
                case 1: p.drawPixmap(x, y, walk6); break;
                case 2: p.drawPixmap(x, y, walk7); break;
                case 3: p.drawPixmap(x, y, walk8); break;
            }
            }}
}
int player::gethit_points(){
    return hit_points;
}
int player::getattack(){
    return attack;
};
int player::getbarrier(){
    return barrier;
}
int player::getspeed(){
    return speed;
}
int player::getX(){
    return x;
}
int player::getY(){
    return y;
}
int player::geiwidth(){
    return image.width();
}
int player::getheight(){
    return image.height();
}
void player::setX(int x){
    this->x=x;
}
void player::setY(int y){
    this->y=y;
}
int player::getwalkindex(){
    return walkindex;
}
int player::getwalktimer(){
    return walktimer;
}
void player::setwalkindex(int x){
    walkindex=x;
}
void player::setwalktimer(int x){
    walktimer=x;
}
void player::set_barrier(int a){
barrier-=a;
if(barrier<=0){
    barrier=0;
}
if(barrier>=5){
    barrier=5;
}
}
player::~player(){
};