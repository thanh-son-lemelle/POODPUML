#ifndef FREEZEPROJECTILE_H
#define FREEZEPROJECTILE_H

#include "Projectile.h"

class FreezeProjectile : public Projectile {
public:
    FreezeProjectile(QVector2D pos,int spd, int dmg, Creep *targ);
    void applyEffect(Creep* target) override;

    void draw(QPainter &painter) override;
};

#endif // FREEZEPROJECTILE_H
