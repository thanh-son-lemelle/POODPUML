#include "TurretFactory.h"
#include "TurretRegular.h"
#include "TurretFreeze.h"

Turret* TurretRegularFactory::createTurret(QVector2D position) {
    Turret* turret = new TurretRegular();
    turret->initialize(position);
    return turret;
}

Turret* TurretFreezeFactory::createTurret(QVector2D position) {
    Turret* turret = new TurretFreeze();
    turret->initialize(position);
    return turret;
}
