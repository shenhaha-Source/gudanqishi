#ifndef BULLET_H
#define BULLET_H

#include <QPixmap>
#include <QRect>

class bullet
{
public:
    bullet(int sx, int sy, double dx, double dy,int type);
    ~bullet();
    void update();
    void draw(QPainter* p);
    QRect rect() ;
    bool isactive() ;
    void setinactive();
    int damage() const { return 1; }
    int  gettype();
private:
    int mytype;
    QPixmap pix;
    int x, y;
    double dx, dy;
    double speed;
    bool active;
};

#endif