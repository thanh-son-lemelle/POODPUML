#include "ObjectPool.h"

// Private constructor
ObjectPool::ObjectPool()
{
    // Constructor
}

// Destructor
ObjectPool::~ObjectPool()
{
    // Make sure to delete all projectiles, turrets, and creeps in the lists
    for (Projectile *projectile : projectiles)
    {
        delete projectile;
    }

    for (Turret *turret : turrets)
    {
        delete turret;
    }

    for (Creep *creep : creeps)
    {
        delete creep;
    }

    for (TurretObserver *observer : observers)
    {
        delete observer;
    }
}

// Static method to get the single instance of the class
ObjectPool &ObjectPool::getInstance()
{
    static ObjectPool instance; // Guaranteed to be destroyed, instantiated on first use
    return instance;
}

// Method to get all projectiles
std::list<Projectile *> &ObjectPool::getProjectiles()
{
    return projectiles;
}

// Method to add projectile
void ObjectPool::addProjectile(Projectile *projectile)
{
    projectiles.push_back(projectile);
}

// Method to remove projectile
void ObjectPool::removeProjectile(Projectile *projectile)
{
    projectiles.remove(projectile);
    delete projectile;
}

// Methods to get all turrets
std::list<Turret *> &ObjectPool::getTurrets()
{
    return turrets;
}

// Method to add turret
void ObjectPool::addTurret(Turret *turret)
{
    turrets.push_back(turret);
    TurretObserver *observer = new TurretObserver(turret);
    observers.push_back(observer);
    for (Creep *creep : creeps)
    {
        // connect(creep, &Creep::moved, observer, &TurretObserver::onCreepMoved);
    }
}

// Method to remove turret
void ObjectPool::removeTurret(Turret *turret)
{
    turrets.remove(turret);
    delete turret;
}

// Methods to get all creeps
std::list<Creep *> &ObjectPool::getCreeps()
{
    return creeps;
}

// Method to add creep
void ObjectPool::addCreep(Creep *creep)
{
    creeps.push_back(creep);
}

void ObjectPool::removeCreep(Creep *creep)
{
    std::list<Projectile *> projectilesToRemove;
    for (Projectile *projectile : projectiles)
    {
        if (projectile->getTarget() == creep)
        {
            projectilesToRemove.push_back(projectile);
        }
    }
    for (Projectile *projectile : projectilesToRemove)
    {
        removeProjectile(projectile);
    }
    creeps.remove(creep);
    delete creep;
}

std::list<TurretObserver *> &ObjectPool::getObservers()
{
    return observers;
}

// Method to update all objects
void ObjectPool::update()
{
    for (Projectile *projectile : projectiles)
    {
        projectile->update();
    }

    for (Turret *turret : turrets)
    {
        turret->update();
    }

    for (Creep *creep : creeps)
    {
        creep->update(1);
    }

    for (TurretObserver *observer : observers)
    {
        observer->update();
    }
    // handleDeadCreeps();
}

void ObjectPool::handleDeadCreeps()
{
    std::list<Creep *> creepsToRemove;
    for (Creep *creep : creeps)
    {
        if (creep->getIsDead())
        {
            creepsToRemove.push_back(creep);
        }
    }

    for (Creep *creep : creepsToRemove)
    {
        creeps.remove(creep);
    }
}
