#include "TurretObserver.h"

TurretObserver::TurretObserver(Turret *turret, QObject *parent) : QObject(parent), turret(turret) {}

void TurretObserver::onCreepMoved(Creep *creep)
{
    if ((turret->getPosition() - creep->getPosition()).length() <= turret->getRange())
    {
        turret->setTarget(creep);
    }
}