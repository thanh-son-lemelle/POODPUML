#include "RegularProjectile.h"
#include "Creep.h"

RegularProjectile::RegularProjectile(QVector2D pos, int spd, int dmg, Creep *targ)
    : Projectile(pos, spd, dmg, targ)
{
}

void RegularProjectile::applyEffect(Creep* target) {
    target->takeDamage(damage);
}

void RegularProjectile::draw(QPainter &painter) {
    painter.setBrush(Qt::red);
    painter.drawEllipse(position.toPointF(), 10, 10);
}
