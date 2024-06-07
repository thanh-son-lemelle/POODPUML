#ifndef TURRETREGULAR_H
#define TURRETREGULAR_H

#include "Turret.h"
#include <QTimer>

class TurretRegular : public Turret {
    Q_OBJECT
public:
    TurretRegular()
    {
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &TurretRegular::fireProjectile);
        timer->start(2000); // Fire every 2 seconds
    }
    void update(float deltaTime) override;
    void draw(QPainter &painter) override;

public slots:
    void fireProjectile() override;
    
};

#endif // TURRETREGULAR_H

