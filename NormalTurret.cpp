#include "NormalTurret.h"
#include "ObjectPool.h"

NormalTurret::NormalTurret(QObject *parent)
    : Turret(parent) {
    // Initialize specific attributes for a normal turret
}

void NormalTurret::draw(QPainter *painter) {
    painter->setBrush(Qt::blue);
    painter->drawEllipse(getPosition().toPointF(), 10, 10); // Draw a circle representing the turret
}

void NormalTurret::fireProjectile() {
    // Create a new projectile
    Projectile *projectile = new Projectile(getPosition(), target, damage, projectileSpeed, this);
    // Add the projectile to the scene
    ObjectPool::getInstance().addProjectile(projectile);
}
