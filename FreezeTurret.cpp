#include "FreezeTurret.h"
#include "ObjectPool.h"

FreezeTurret::FreezeTurret(QPixmap pixmap, QObject *parent)
    : Turret(pixmap, parent)
{
    // Initialize specific attributes for a freezing turret
}

void FreezeTurret::draw(QPainter *painter) {
    painter->setBrush(Qt::cyan);
    painter->drawEllipse(getPosition().toPointF(), 10, 10);
}

void FreezeTurret::fireProjectile() {
    // Create a new projectile
    Projectile *projectile = new Projectile(getPosition(), target, damage, projectileSpeed, this);
    // Add the projectile to the scene
    ObjectPool::getInstance().addProjectile(projectile);
}