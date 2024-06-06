#include "GameScene.h"
#include "ObjectPool.h"
#include <QPainter>


GameScene::GameScene(QWidget *parent)
    : QWidget(parent) {}


void GameScene::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    QPixmap backgroundImage(":/images/assets/map.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), backgroundImage);

    ObjectPool &objectPool = ObjectPool::getInstance();
    for (Projectile *projectile : objectPool.getProjectiles())
    {
        projectile->draw(&painter);
    }
    for  (Turret *turret : objectPool.getTurrets())
    {
        turret->draw(&painter);
    }
    for (Creep *creep : objectPool.getCreeps())
    {
        creep->draw(&painter);
    }
}
