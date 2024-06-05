#include "FreezeTurret.h"
#include "ObjectPool.h"

FreezeTurret::FreezeTurret( QObject *parent)
    : Turret(parent)
{
    // Initialize specific attributes for a freezing turret
}

void FreezeTurret::draw(QPainter *painter) {
    painter->setBrush(Qt::cyan);
    painter->drawEllipse(getPosition().toPointF(), 20, 20);
}

void FreezeTurret::fireProjectile() {
    // Create a new projectile
    Projectile *projectile = new Projectile(getPosition(), target, damage, projectileSpeed, this, ProjectileType::Freeze);
    // Add the projectile to the scene
    ObjectPool::getInstance().addProjectile(projectile);
}
