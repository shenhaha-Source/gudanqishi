#ifndef RULERWINDOW_H
#define RULERWINDOW_H
#include <QDialog>
#include <QPaintEvent>
#include <QMouseEvent>
class rulerwindow : public QDialog
{
    Q_OBJECT
public:
    explicit rulerwindow(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
signals:
    void showmainwindow();
};



#endif // RULEWINDOW_H