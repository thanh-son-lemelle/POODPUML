#include "NormalTurret.h"
#include "ObjectPool.h"

NormalTurret::NormalTurret(QObject *parent)
    : Turret( parent)
{
}

void NormalTurret::draw(QPainter *painter) {
    painter->save();

    // Set the color and shape of the projectile
    painter->setBrush(Qt::blue);
    painter->setPen(Qt::NoPen);

    // Draw the projectile as a circle at its current position
    painter->drawEllipse(position.toPointF(), 20, 20);

    // Restore the painter's state
    painter->restore();
}

void NormalTurret::fireProjectile() {
    // Create a new projectile
    Projectile *projectile = new Projectile(getPosition(), target, damage, projectileSpeed, this, ProjectileType::Normal);
    // Add the projectile to the scene
    ObjectPool::getInstance().addProjectile(projectile);
}
