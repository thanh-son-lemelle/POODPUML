#include "GameScene.h"
#include "ObjectPool.h"
#include <QPainter>


GameScene::GameScene(QWidget *parent)
    : QWidget(parent) {}

void GameScene::addTurret(Turret *turret) {
    turrets.append(turret);
    update(); // Request a repaint
}

void GameScene::addCreep(Creep *creep) {
    creeps.append(creep);
    update();
}

void GameScene::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    QPixmap backgroundImage(":/images/assets/map.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), backgroundImage);

    for (Turret *turret : turrets)
    {
        turret->draw(&painter);
    }
    ObjectPool &objectPool = ObjectPool::getInstance();
    for (Projectile *projectile : objectPool.getProjectiles())
    {
        projectile->draw(&painter);
    }
    for (Creep *creep : creeps)
    {
        creep->draw(&painter);
        // painter.drawPixmap(creep->pos().toPoint(), creep->pixmap());
    }
}
