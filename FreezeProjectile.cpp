#include "FreezeProjectile.h"
#include "Creep.h"

FreezeProjectile::FreezeProjectile(QVector2D pos, int spd, int dmg, Creep *targ)
: Projectile(pos, spd, dmg, targ)
{
}

void FreezeProjectile::applyEffect(Creep* target) {
    target->takeDamage(damage);
    target->freeze(1);
}

void FreezeProjectile::draw(QPainter &painter) {
    painter.setBrush(Qt::blue);
    painter.drawEllipse(position.toPointF(), 10, 10);
}
