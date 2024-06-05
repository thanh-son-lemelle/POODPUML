#include "NormalTurret.h"
#include "ObjectPool.h"

NormalTurret::NormalTurret(QObject *parent)
    : Turret( parent)
{
}

void NormalTurret::draw(QPainter *painter) {
    painter->setBrush(Qt::blue);
    painter->drawEllipse(getPosition().toPointF(), 20, 20); // Draw a circle representing the turret
}

void NormalTurret::fireProjectile() {
    // Create a new projectile
    Projectile *projectile = new Projectile(getPosition(), target, damage, projectileSpeed, this, ProjectileType::Normal);
    // Add the projectile to the scene
    ObjectPool::getInstance().addProjectile(projectile);
}
