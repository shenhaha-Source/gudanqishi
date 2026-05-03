#ifndef MONSTER_H
#define MONSTER_H
#endif // MONSTER_H
#include<QPixmap>
#include<QPainter>
class jimonster{
private:
    int hit_points;
    int attack;
    int x;
    int y;
    int speed;
    int type;
    double dx,dy;
    QPoint targetpoint;
    QPixmap image;
public:
    jimonster(int type);
    ~jimonster();
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
    void update();
    QRect rect() const;
};
