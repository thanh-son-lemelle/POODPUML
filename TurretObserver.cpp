#include "TurretObserver.h"
#include "ObjectPool.h"

TurretObserver::TurretObserver(Turret *turret)
{
    this->turret = turret;
}

TurretObserver::~TurretObserver()
{
}

void TurretObserver::update()
{
    ObjectPool &objectPool = ObjectPool::getInstance();
    if (turret->getTarget() == nullptr)
    {
        onCreepEnteredRange(objectPool);
    }
    else
    {
        onCreepLeftRange(objectPool);
    }
}
void TurretObserver::onCreepEnteredRange(ObjectPool &objectPool)
{
    for (Creep *creep : objectPool.getCreeps())
    {
        if (turret->getRange() >= QVector2D(turret->getPosition() - creep->getPosition()).length())
        {
            turret->setTarget(creep);
            break;
        }
    }
}

void TurretObserver::onCreepLeftRange(ObjectPool &objectPool)
{
    if (turret->getTarget() != nullptr)
    {
        if (turret->getRange() < QVector2D(turret->getPosition() - turret->getTarget()->getPosition()).length())
        {
            removeTarget(objectPool);
            turret->setTarget(nullptr);
        }
    }
}

void TurretObserver::removeTarget(ObjectPool &objectPool)
{
    if (turret->getTarget()->getIsDead())
    {
        objectPool.removeCreep(turret->getTarget());
    }
}