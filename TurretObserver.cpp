#include "TurretObserver.h"
#include "ObjectPool.h"

TurretObserver::TurretObserver(Turret *turret) : turret(turret)
{
}

TurretObserver::~TurretObserver() {}

void TurretObserver::update()
{
    removeTarget();
    scanTarget();
}

void TurretObserver::removeTarget()
{
    ObjectPool &objectPool = ObjectPool::getInstance();
    if (turret->getTarget() != nullptr)
    {
        if (turret->getTarget()->getIsDead())
        {
                objectPool.removeCreep(turret->getTarget());
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