#include "mainwindow.h"
#include "gamewindow.h"
#include"guanqiawindow.h"
#include"rulerwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 设置窗口大小
    this->setFixedSize(1600, 1000);
    this->setWindowTitle("孤勇骑士 - 主菜单");
    m_volumeDialog = new VolumeDialog(this);
    // 1. 创建【开始游戏】透明按钮
    startBtn = new QPushButton(this);
    startBtn->setGeometry(700, 330, 200, 60);
    startBtn->setStyleSheet("background: transparent; border: none;");

    // 2. 【选择关卡】按钮
    guanqiaBtn = new QPushButton(this);
    guanqiaBtn->setGeometry(700, 430, 200, 60);
    guanqiaBtn->setStyleSheet("background: transparent; border: none;");

    // 3. 【规则】按钮
    ruleBtn = new QPushButton(this);
    ruleBtn->setGeometry(700, 520, 200, 80);
    ruleBtn->setStyleSheet("background: transparent; border: none;");
    // 4. 连接信号与槽
    vulumBtn=new QPushButton(this);
    vulumBtn->setGeometry(700, 620, 200, 80);
    vulumBtn->setStyleSheet("background: transparent; border: none;");
    connect(startBtn, &QPushButton::clicked, this, &MainWindow::onStartGameClicked);
    connect(guanqiaBtn,&QPushButton::clicked,this,&MainWindow::onguanqiaClicked);
    connect(ruleBtn,&QPushButton::clicked,this,&MainWindow::onRuleClicked);
    connect(vulumBtn,&QPushButton::clicked,this,&MainWindow::onvulueClicked);
    m_mainAudio = new QAudioOutput(this);
    m_mainMusic = new QMediaPlayer(this);

    m_mainMusic->setSource(QUrl("qrc:/shengyin/game_bgm.mp3"));
    m_mainMusic->setAudioOutput(m_mainAudio);
    connect(m_volumeDialog, &VolumeDialog::volumeChanged, this, [=]() {
        m_mainAudio->setVolume(g_menuVolume);
    });
    connect(m_mainMusic, &QMediaPlayer::mediaStatusChanged, this, [=](QMediaPlayer::MediaStatus status){
        if(status == QMediaPlayer::EndOfMedia) {
            m_mainMusic->setPosition(0);
            m_mainMusic->play();
        }
    });

    m_mainMusic->play();
}
// 绘制背景图
void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    QPixmap bgPix(":/gamewindow/0.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), bgPix);
}
void MainWindow::onStartGameClicked()
{
    m_mainMusic->stop();
    this->hide();
    GameWindow *gameWin = new GameWindow(guanqia);
    gameWin->setAttribute(Qt::WA_DeleteOnClose);
    gameWin->show();
    connect(gameWin, &GameWindow::playerdie, this, [=]() {
        gameWin->hide();
        this->show();
         m_mainMusic->play();
    });
    connect(gameWin, &GameWindow::monsterdie, this, [=]() {
        gameWin->hide();
        this->show();
         m_mainMusic->play();
    });
}
void MainWindow::onguanqiaClicked() {
    this->hide();
    guanqiawindow*guan=new guanqiawindow();
    guan->setAttribute(Qt::WA_DeleteOnClose);
    guan->show();
    connect(guan, &guanqiawindow::destroyed, this, [this, guan]() {
        this->guanqia = guan->getChoosenguanqia();
    });
    connect(guan,&guanqiawindow::showmainwindow,[this](){
        this->show();
    });
}

void MainWindow::onRuleClicked() {

    rulerwindow*rulers=new rulerwindow();
    rulers->setAttribute(Qt::WA_DeleteOnClose);
    rulers->show();
    connect(rulers, &rulerwindow::showmainwindow, [this]() {
        this->show();
    });
}
void MainWindow::onvulueClicked(){
    m_volumeDialog->show();
    return;
}
MainWindow::~MainWindow()
{

}
