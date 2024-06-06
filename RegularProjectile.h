#ifndef REGULARPROJECTILE_H
#define REGULARPROJECTILE_H

#include "Projectile.h"

class RegularProjectile : public Projectile {
public:
    RegularProjectile(QVector2D pos, int spd, int dmg, Creep *targ);
    void applyEffect(Creep* target) override;

    void draw(QPainter &painter) override;
};

#endif // REGULARPROJECTILE_H
