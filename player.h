#ifndef PLAYER_H
#define PLAYER_H
#endif // PLAYER_H
#include<QPixmap>
#include<QPainter>
class player{
private:
    int hit_points=30;
    int barrier;
    int speed;
    int attack;
    int x;
    int y;
    int walkindex;
    int walktimer;
    QPoint weizhi;
    QPixmap image;
    QPixmap walk1;
    QPixmap walk2;
    QPixmap walk3;
    QPixmap walk4;
    QPixmap walk5;
    QPixmap walk6;
    QPixmap walk7;
    QPixmap walk8;
public:
    bool isrightmove;
    bool isleftmove;
    bool stopleft;
    bool stopright;
    player();
    ~player();
    int gethit_points();
    void sethit_points(int a);
    void moveup();
    void movedown();
    void moveleft();
    void moveright();
    void draw(QPainter & p);
    int getX();
    int getY();
    int geiwidth();
    int getheight();
    void setX(int x);
    void setY(int y);
    int getwalkindex();
    int getwalktimer();
    void setwalkindex(int x);
    void setwalktimer(int y);
    int getbarrier();
    int getattack();
    int getspeed();
    void set_barrier(int a);



};
