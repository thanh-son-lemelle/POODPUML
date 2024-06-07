#include "TurretRegular.h"
#include "RegularProjectile.h"
#include "ObjectPool.h"
#include <QPainter>
#include <QPixmap>

void TurretRegular::fireProjectile() {
    // Implementation of firing a regular projectile
    ObjectPool &objectPool = ObjectPool::getInstance();
    Projectile* projectile = new RegularProjectile(position, 100, 10, target);
    objectPool.addProjectile(projectile);
}

void TurretRegular::update(float deltaTime) {
    // Implementation of updating the turret
    if (target != nullptr) {
        fireProjectile();
    }
}

void TurretRegular::draw(QPainter &painter) {
    QPixmap image(":/RegularTurret.png");
    QPixmap scaledImage = image.scaled(WIDTH, HEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    painter.drawPixmap(position.toPointF(), scaledImage);
}
