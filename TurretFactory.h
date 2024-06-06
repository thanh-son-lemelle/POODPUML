#ifndef TURRETFACTORY_H
#define TURRETFACTORY_H

#include <qvector2d.h>
#include "Turret.h"

class TurretFactory {
public:
    virtual Turret* createTurret(QVector2D position) = 0;
};

class TurretRegularFactory : public TurretFactory {
public:
    Turret* createTurret(QVector2D position) override;
};

class TurretFreezeFactory : public TurretFactory {
public:
    Turret* createTurret(QVector2D position) override;
};

#endif // TURRETFACTORY_H
