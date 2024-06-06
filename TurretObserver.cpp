#include "TurretObserver.h"
#include "ObjectPool.h"

TurretObserver::TurretObserver(Turret *turret) : turret(turret)
{
}

TurretObserver::~TurretObserver() {}

void TurretObserver::update()
{
    loseTarget();
    scanTarget();
}

void TurretObserver::removeTarget()
{
    if (turret->getTarget()->getIsDead())
    {
        ObjectPool &objectPool = ObjectPool::getInstance();
        objectPool.removeCreep(turret->getTarget());
    }
}



void TurretObserver::loseTarget()
{
    if (turret->getTarget() != nullptr)
    {
        if (turret->getRange() < QVector2D(turret->getPosition() - turret->getTarget()->getPosition()).length())
        {
            removeTarget();
            turret->setTarget(nullptr);
        }
    }
}
void TurretObserver::checkForTargetInRange(std::list<Creep *> creeps)
{
    for (Creep *creep : creeps)
    {
        if (turret->getRange() >= QVector2D(turret->getPosition() - creep->getPosition()).length())
        {
            turret->setTarget(creep);
            break;
        }
    }
}

void TurretObserver::scanTarget()
{
    ObjectPool &objectPool = ObjectPool::getInstance();
    if (turret->getTarget() == nullptr)
    {
        checkForTargetInRange(objectPool.getCreeps());
    }
}