#ifndef FREEZEPROJECTILE_H
#define FREEZEPROJECTILE_H

#include "Projectile.h"

class FreezeProjectile : public Projectile {
public:
    void applyEffect(Creep* target) override;
};

#endif // FREEZEPROJECTILE_H
