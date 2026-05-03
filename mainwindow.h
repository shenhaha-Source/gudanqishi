#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QSlider>
#include <QDialog>
#include"volumedialog.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    // 绘制背景图
    void paintEvent(QPaintEvent *event) override;

private slots:
    // 开始游戏按钮点击事件
    void onvulueClicked();
    void onStartGameClicked();
    void onguanqiaClicked();
    void onRuleClicked();
private:
    int guanqia=1;
    QPushButton *startBtn;
    QPushButton *guanqiaBtn;
    QPushButton *ruleBtn;
    QPushButton *vulumBtn;
    QMediaPlayer *m_mainMusic;
    QAudioOutput *m_mainAudio;
    VolumeDialog *m_volumeDialog;
};

#endif // MAINWINDOW_H