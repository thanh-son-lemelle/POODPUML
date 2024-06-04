#include "TurretFactory.h"
#include "NormalTurret.h"
#include "FreezeTurret.h"

Turret* TurretFactory::createTurret(TurretType type, QObject *parent) {
    QPixmap pixmap(":/images/assets/creep.png");
    switch (type) {
    case TurretType::Normal:
        return new NormalTurret(parent);
    case TurretType::Freeze:
        return new FreezeTurret(parent);
    default:
        return nullptr;
    }
}

