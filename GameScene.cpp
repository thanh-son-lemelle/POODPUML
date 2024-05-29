#include "GameScene.h"
#include <QPainter>

GameScene::GameScene(QWidget *parent)
    : QWidget(parent) {}

void GameScene::addTurret(Turret *turret) {
    turrets.append(turret);
    update(); // Request a repaint
}

void GameScene::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    for (Turret *turret : turrets) {
        turret->draw(&painter);
    }
}
