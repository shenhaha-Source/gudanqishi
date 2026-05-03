#ifndef OBSTACLE_H
#define OBSTACLE_H
#endif // OBSTACLE_H
#include<QPixmap>
#include<QPainter>
class obstacle{
private:
    int x;
    int y;
    QPixmap image;
public:
    obstacle();
    int getheight();
    int getwidth();
    void setpoints(int x,int y);
    void setpicture(const QString& path);
    void draw(QPainter& painter);
    QRect rect() const;
    int getX();
    int getY();
    ~obstacle();
};