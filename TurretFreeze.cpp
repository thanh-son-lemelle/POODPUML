#include "TurretFreeze.h"
#include "FreezeProjectile.h"
#include "ObjectPool.h"

#include <QPainter>
#include <QPixmap>

void TurretFreeze::fireProjectile() {
    if (target == nullptr) {
        return;
    }
    ObjectPool &objectPool = ObjectPool::getInstance();
    Projectile* projectile = new FreezeProjectile(position, 500, 2, target);
    objectPool.addProjectile(projectile);
}

void TurretFreeze::update(float deltaTime) {
    // if (target != nullptr) {
    //     // fireProjectile();
    // }
}

void TurretFreeze::draw(QPainter &painter) {
    QPixmap image(":/FreezeTurret.png");
    QPixmap scaledImage = image.scaled(WIDTH, HEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    // Center the image on the position
    QPointF centeredPosition = position.toPointF() - QPointF(scaledImage.width() / 2, scaledImage.height() / 2);
    painter.drawPixmap(centeredPosition, scaledImage);
}
