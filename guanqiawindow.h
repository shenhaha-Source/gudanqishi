#ifndef GUANQIAWINDOW_H
#define GUANQIAWINDOW_H
#endif // GUANQIAWINDOW_H
#include <QDialog>
#include <QPushButton>
#include <QPixmap>
#include<QWidget>
class guanqiawindow:public QDialog{
    Q_OBJECT
public:
    explicit guanqiawindow(QDialog*parent = nullptr);
    ~guanqiawindow();
    int getChoosenguanqia() ;

    void setchosenlevel(int a);
protected:
    void paintEvent(QPaintEvent *event) override;
signals:
    void showmainwindow();
private slots:
    void choose1();
    void choose2();
    void choose3();
private:

    int chosenlevel = 1;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
};
