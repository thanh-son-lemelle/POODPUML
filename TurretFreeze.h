#ifndef TURRETFREEZE_H
#define TURRETFREEZE_H

#include "Turret.h"

class TurretFreeze : public Turret {
public:
    void fireProjectile() override;
    void update(float deltaTime) override;
    void draw(QPainter &painter) override;
};

#endif // TURRETFREEZE_H
