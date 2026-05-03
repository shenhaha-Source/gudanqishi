#include "volumedialog.h"
float g_menuVolume = 0.5f;
float g_gameBgmVolume = 0.5f;
float g_hurtVolume = 0.6f;
VolumeDialog::VolumeDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("音量调节");
    setFixedSize(450, 300);
    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
    setStyleSheet("background-color: #1b1b1b; color: white;");
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setSpacing(25);
    layout->setContentsMargins(40,40,40,40);
    // 主界面音乐
    lab_menu = new QLabel("主界面音乐: 50%");
    sld_menu = new QSlider(Qt::Horizontal);
    sld_menu->setRange(0, 100);
    sld_menu->setValue(50);
    layout->addWidget(lab_menu);
    layout->addWidget(sld_menu);

    // 游戏音
    lab_game = new QLabel("游戏音乐: 50%");
    sld_game = new QSlider(Qt::Horizontal);
    sld_game->setRange(0, 100);
    sld_game->setValue(50);
    layout->addWidget(lab_game);
    layout->addWidget(sld_game);

    // 受击音
    lab_hurt = new QLabel("受击音效: 60%");
    sld_hurt = new QSlider(Qt::Horizontal);
    sld_hurt->setRange(0, 100);
    sld_hurt->setValue(60);
    layout->addWidget(lab_hurt);
    layout->addWidget(sld_hurt);

    connect(sld_menu, &QSlider::valueChanged, this, &VolumeDialog::onValueChanged);
    connect(sld_game, &QSlider::valueChanged, this, &VolumeDialog::onValueChanged);
    connect(sld_hurt, &QSlider::valueChanged, this, &VolumeDialog::onValueChanged);
}

void VolumeDialog::onValueChanged()
{
    lab_menu->setText(QString("主界面音乐: %1%").arg(sld_menu->value()));
    lab_game->setText(QString("游戏音乐: %1%").arg(sld_game->value()));
    lab_hurt->setText(QString("受击音效: %1%").arg(sld_hurt->value()));
    g_menuVolume = sld_menu->value() / 100.0f;
    g_gameBgmVolume = sld_game->value() / 100.0f;
    g_hurtVolume = sld_hurt->value() / 100.0f;
    emit volumeChanged();
}
float VolumeDialog::menuVolume() const {
    return sld_menu->value() / 100.0f;
}
float VolumeDialog::gameBgmVolume() const {
    return sld_game->value() / 100.0f;
}
float VolumeDialog::hurtSoundVolume() const {
    return sld_hurt->value() / 100.0f;
}