#include "Projectile.h"

Projectile::Projectile(QVector2D turretPosition, Creep *target, int damage, int speed, QObject *parent, ProjectileType type)
: position(turretPosition), target(target), damage(damage), speed(speed), QObject(parent), type(type)
{
}

Projectile::~Projectile()
{
}


void Projectile::draw(QPainter *painter)
{
    painter->save();

    // Set the color and shape of the projectile
    painter->setBrush(Qt::white);
    painter->setPen(Qt::NoPen);

    // Draw the projectile as a circle at its current position
    painter->drawEllipse(position.toPointF(), 2, 2);

    // Restore the painter's state
    painter->restore();
}
void Projectile::update()
{
    // Move towards target
    if (target != nullptr)
    {
        direction = target->getPosition() - position;
        direction.normalize();
    }
    position += direction * speed;

    // Check if we hit the target
    // if (position.distanceToPoint(target->getPosition()) < 5)
    // {
    //     target->takeDamage(damage);
    //     delete this;
    // }
}

