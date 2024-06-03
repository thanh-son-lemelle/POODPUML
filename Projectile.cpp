#include "Projectile.h"

Projectile::Projectile(QVector2D turretPosition, Creep *target, int damage, int speed, QObject *parent)
: position(turretPosition), target(target), damage(damage), speed(speed), QObject(parent)
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
    // QVector2D direction = target->getPosition() - position;
    //direction.normalize();
    //position += direction * speed; 
    position += QVector2D(1, 0); 

    // Check if we hit the target
    // if (position.distanceToPoint(target->getPosition()) < 5)
    // {
    //     target->takeDamage(damage);
    //     delete this;
    // }
}