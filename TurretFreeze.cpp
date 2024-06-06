#include "TurretFreeze.h"
#include "FreezeProjectile.h"
#include "ObjectPool.h"

#include <QPainter>
#include <QPixmap>

void TurretFreeze::fireProjectile() {
    ObjectPool &objectPool = ObjectPool::getInstance();
    Projectile* projectile = new FreezeProjectile(position, 100, 10, target);
    objectPool.addProjectile(projectile);
}

void TurretFreeze::update(float deltaTime) {
}

void TurretFreeze::draw(QPainter &painter) {
    QPixmap image(":/FreezeTurret.png");
    QPixmap scaledImage = image.scaled(WIDTH, HEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    painter.drawPixmap(position.toPointF(), scaledImage);
}
