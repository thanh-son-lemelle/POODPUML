#include "FreezeTurret.h"
#include "ObjectPool.h"

FreezeTurret::FreezeTurret( QObject *parent)
    : Turret(parent)
{
    // Initialize specific attributes for a freezing turret
}

void FreezeTurret::draw(QPainter *painter) {
    painter->save();

    // Set the color and shape of the projectile
    painter->setBrush(Qt::cyan);
    painter->setPen(Qt::NoPen);

    // Draw the projectile as a circle at its current position
    painter->drawEllipse(position.toPointF(), 20, 20);

    // Restore the painter's state
    painter->restore();
}

void FreezeTurret::fireProjectile() {
    // Create a new projectile
    Projectile *projectile = new Projectile(getPosition(), target, damage, projectileSpeed, this, ProjectileType::Freeze);
    // Add the projectile to the scene
    ObjectPool::getInstance().addProjectile(projectile);
}
