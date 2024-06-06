#ifndef REGULARPROJECTILE_H
#define REGULARPROJECTILE_H

#include "Projectile.h"

class RegularProjectile : public Projectile {
public:
    void applyEffect(Creep* target) override;
};

#endif // REGULARPROJECTILE_H
