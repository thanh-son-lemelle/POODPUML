#ifndef TURRETREGULAR_H
#define TURRETREGULAR_H

#include "Turret.h"

class TurretRegular : public Turret {
public:
    void fireProjectile() override;
    void update(float deltaTime) override;
    void draw(QPainter &painter) override;
};

#endif // TURRETREGULAR_H

