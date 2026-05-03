#ifndef VOLUMEDIALOG_H
#define VOLUMEDIALOG_H

#include <QDialog>
#include <QSlider>
#include <QLabel>
#include <QVBoxLayout>
extern float g_menuVolume;    // 主界面音乐
extern float g_gameBgmVolume; // 游戏BGM
extern float g_hurtVolume;    // 受击音效
class VolumeDialog : public QDialog
{
    Q_OBJECT
public:
    explicit VolumeDialog(QWidget *parent = nullptr);

    float menuVolume() const;
    float gameBgmVolume() const;
    float hurtSoundVolume() const;

signals:
    void volumeChanged();

private slots:
    void onValueChanged();

private:
    QSlider *sld_menu;
    QSlider *sld_game;
    QSlider *sld_hurt;

    QLabel *lab_menu;
    QLabel *lab_game;
    QLabel *lab_hurt;
};

#endif