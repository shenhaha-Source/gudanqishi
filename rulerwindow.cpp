#include "rulerwindow.h"
#include <QPainter>

rulerwindow::rulerwindow(QWidget *parent) : QDialog(parent)
{
    // 窗口大小
    setFixedSize(800, 800);
    setWindowTitle("游戏规则");
}
void rulerwindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(rect(), QColor(255, 250, 240));
    painter.setPen(Qt::darkBlue);
    painter.setFont(QFont("微软雅黑", 28, QFont::Bold));
    int titleY = height() * 0.1; // 标题在窗口1/10高度处
    painter.drawText(0, titleY, width(), 60, Qt::AlignCenter, "游戏规则");
    int midX = width() / 2;       // 窗口中线（分栏依据）
    int leftStartX = 50;          // 左栏起始X
    int rightStartX = midX + 20;  // 右栏起始X（中线偏右20px）
    int baseY = titleY + 80;      // 文字起始Y（标题下方80px）
    int lineHeight = 40;          // 行间距（恢复40也不会超）
    painter.setPen(Qt::black);
    painter.setFont(QFont("微软雅黑", 18, QFont::Medium));
    painter.drawText(leftStartX, baseY, "🎮 操作键位");
    painter.setFont(QFont("微软雅黑", 16));
    painter.drawText(leftStartX + 20, baseY + lineHeight, "W. 向上移动");
    painter.drawText(leftStartX + 20, baseY + 2*lineHeight, "S. 向下移动");
    painter.drawText(leftStartX + 20, baseY + 3*lineHeight, "A. 向左移动");
    painter.drawText(leftStartX + 20, baseY + 4*lineHeight, "D. 向右移动");
    painter.drawText(leftStartX + 20, baseY + 5*lineHeight, "K. 攻击键位");
    painter.drawText(leftStartX + 20, baseY + 6*lineHeight, "L. 技能键位");
    painter.setFont(QFont("微软雅黑", 18, QFont::Medium));
    painter.drawText(rightStartX, baseY, "📋 关卡规则");
    painter.setFont(QFont("微软雅黑", 15));
    painter.drawText(rightStartX + 20, baseY + lineHeight, "1. 第一关/第二关：消灭所有怪物胜利");
    painter.drawText(rightStartX + 20, baseY + 2*lineHeight, "2. 第三关：击败最终Boss即可胜利");
    painter.drawText(rightStartX + 20, baseY + 3*lineHeight, "⚠️ 特别注意：");
    painter.drawText(rightStartX + 40, baseY + 4*lineHeight, "第二关炸弹人触碰角色扣5滴血");
    painter.setPen(Qt::red);
    painter.setFont(QFont("微软雅黑", 14));
    int tipY = height() * 0.85; // 提示语在窗口85%高度处
    painter.drawText(0, tipY, width(), 40, Qt::AlignCenter, "【点击任意位置返回主界面】");
}

void rulerwindow::mousePressEvent(QMouseEvent *event)
{
    emit showmainwindow();
    close();
    QDialog::mousePressEvent(event);
}
