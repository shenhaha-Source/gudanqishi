#ifndef MONSTER_H
#define MONSTER_H
#endif // MONSTER_H
#include<QPixmap>
#include<QPainter>
class monster{
private:
    int hit_points;
    int attack;
    int x;
    int y;
    int speed;
    int type;
    double dx,dy;
    int bornx;
    int borny;
    QPoint targetpoint;
    QPixmap image;
    int r1;
    int r2;
    void randomdirection();
public:
    void takedamage(int val);
    bool isdead() const;
    monster(int type);
    ~monster();
    int gethit_points();
    int getattacK();
    int getX();
    int getY();
    int getspeed();
    void setX(int x);
    void setY(int y);
    void sethit_points(int x);
    void setattack(int x);
    void setspeed(int a);
    void darw(QPainter &p);
    int gettype();
    void intial(int a);
    void setpoints(int x,int y);
    int  getheigth();
    int  getwidth();
    void setsudu(double  x,double y);
    void settarget(int x ,int y);
    int getr1();
    int getr2();
    void update();
    QRect rect() const;
};
