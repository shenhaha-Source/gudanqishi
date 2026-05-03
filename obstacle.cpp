#include"obstacle.h"
obstacle::obstacle(){
    x=0,y=0;
}
int obstacle:: getheight(){
    return image.height();
}
int obstacle::getwidth(){
    return image.width();
}
void obstacle::setpoints(int x,int y){
    this->x=x;
    this->y=y;
}
void obstacle::setpicture(const QString& path){
    image.load(path);
}
void obstacle:: draw(QPainter& painter){
    if (!image.isNull()) {
        painter.drawPixmap(x, y, image);
    }
}
QRect obstacle::rect() const{
    return QRect(x, y, image.width(), image.height());
}
int obstacle::getX(){
    return x;
}
int obstacle::getY(){
    return y;
}
obstacle::~obstacle(){}