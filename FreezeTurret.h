#ifndef FREEZETURRET_H
#define FREEZETURRET_H

#include "turret.h"
#include "projectile.h"

class FreezeTurret : public Turret {
public:
    explicit FreezeTurret(QObject *parent = nullptr);
    void draw(QPainter *painter) override;

    void fireProjectile() override;
};

#endif // FREEZERTURRET_H
