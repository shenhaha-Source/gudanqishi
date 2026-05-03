#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QWidget>
#include"player.h"
#include<QTimer>
#include"monster.h"
#include"jimonster.h"
#include"bullet.h"
#include"mainwindow.h"
#include"obstacle.h"
#include <QMediaPlayer>
#include <QAudioOutput>
class GameWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GameWindow(int level, QWidget *parent = nullptr);
    void playerdead();
    void monsterdead();
    void drawSkill(QPainter* p, int x, int y, int size,
                    QPixmap& icon, int leftMs, int totalMs);
signals:
    void playerdie();
    void monsterdie();
protected:
    void paintEvent(QPaintEvent*event) override;
    void keyPressEvent(QKeyEvent*event) override;
    void keyReleaseEvent(QKeyEvent*event) override;
private:
    QList<obstacle*> m_obstacles;
    MainWindow*m_window;
    player qishi;
    QPixmap m_skill1Icon;
    int m_skill1TotalCd;   // 总冷却 毫秒
    int m_skill1LeftCd;    // 剩余冷却 毫秒
    bool KeyW=false;
    bool keyA=false;
    bool keyS=false;
    bool keyD=false;
    bool keyK=false;
    int time1=10;
    int time2=10;
    int time3=50;
    int time4=50;
    int time5=110;
    int time6=110;
    int time7=5000;
    int time8=5000;
    int time9=500;
    int time10=500;
    int wodelevel;
    int fangxiang;
    int cur=1;
    bool kaka=false;
    QMediaPlayer *m_gameMusic;
    QAudioOutput *m_gameAudio;
    QMediaPlayer* m_hurtSound;
    QAudioOutput* m_hurtAudio;
    QMediaPlayer *m_bossgame;
    QAudioOutput *m_bossaudio;
    std::vector<bullet*> m_bullets;
    QList<monster*> m_monsterList;
    jimonster *tujibing;
    QTimer*gametimer;
    QPixmap bgPix;
    void shootbullet();
    void level1();
    void level2();
    void level3();
    void clearLevel();
private slots:
    void gameupdate();
};

#endif // GAMEWINDOW_H