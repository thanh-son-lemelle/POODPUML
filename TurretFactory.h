#ifndef TURRETFACTORY_H
#define TURRETFACTORY_H

#include "turret.h"

enum class TurretType {
    Normal,
    Freeze
};

class TurretFactory {
public:
    static Turret* createTurret(TurretType type, QObject *parent = nullptr);
};

#endif // TURRETFACTORY_H
