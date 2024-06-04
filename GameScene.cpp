#include "GameScene.h"
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
    for (Turret *turret : turrets) {
        turret->draw(&painter);
    }
    for (Creep* creep : creeps) {
        painter.drawPixmap(creep->pos(), creep->pixmap());
    }
}
