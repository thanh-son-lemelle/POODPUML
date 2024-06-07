#ifndef TURRETFREEZE_H
#define TURRETFREEZE_H

#include "Turret.h"
#include <QTimer>

class TurretFreeze : public Turret{
    Q_OBJECT
public:
    TurretFreeze()
    {
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &TurretFreeze::fireProjectile);
        timer->start(2000); // Fire every 2 seconds
    }
    void fireProjectile() override;
    void update(float deltaTime) override;
    void draw(QPainter &painter) override;
};

#endif // TURRETFREEZE_H
