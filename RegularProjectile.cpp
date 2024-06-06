#include "RegularProjectile.h"
#include "Creep.h"

void RegularProjectile::applyEffect(Creep* target) {
    target->takeDamage(damage);
}
