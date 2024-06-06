#include "Projectile.h"
#include "Creep.h"


Projectile::Projectile(QVector2D pos, int spd, int dmg, Creep *targ)
: position(pos), speed(spd), damage(dmg), target(targ)
{
}

void Projectile::update(float deltaTime) {
    if (target != nullptr) {
        direction = target->getPosition() - position;
        direction.normalize();
    }
    // position += direction * deltaTime * speed;
    position += QVector2D(1, 0) * deltaTime * speed;

}
