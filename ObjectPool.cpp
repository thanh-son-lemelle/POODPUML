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

    for (Turret *turret : turrets)
    {
        delete turret;
    }

    for (Creep *creep : creeps)
    {
        delete creep;
    }

    for (Projectile *projectile : projectiles)
    {
        delete projectile;
    }

    for (TurretObserver *observer : observers)
    {
        delete observer;
    }

    // Clear the lists
    turrets.clear();
    creeps.clear();
    projectiles.clear();
    observers.clear();
}

// Static method to get the single instance of the class
ObjectPool &ObjectPool::getInstance()
{
    static ObjectPool instance; // Guaranteed to be destroyed, instantiated on first use
    return instance;
}


// ======================================= TURRET =======================================
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
}

// Method to remove turret
void ObjectPool::removeTurret(Turret *turret)
{
    turrets.remove(turret);
    delete turret;
}

// ======================================= CREEP =======================================
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

// Method to remove creep
void ObjectPool::removeCreep(Creep *creep)
{
    for (Projectile *projectile : projectiles)
    {
        if (projectile->getTarget() == creep)
        {
            projectile->setTarget(nullptr);
        }
    }
    for (Turret *turret : turrets)
    {
        if (turret->getTarget() == creep)
        {
            turret->setTarget(nullptr);
        }
    }
    creeps.remove(creep);
    delete creep;
}

// ======================================= PROJECTILE =======================================
// Methods to get all projectiles
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

// ======================================= OBSERVER =======================================
// Methods to get all observers
std::list<TurretObserver *> &ObjectPool::getObservers()
{
    return observers;
}

// Method to add observer
void ObjectPool::addObserver(TurretObserver *observer)
{
    observers.push_back(observer);
}

// Method to remove observer
void ObjectPool::removeObserver(TurretObserver *observer)
{
    observers.remove(observer);
    delete observer;
}

// Method to update all objects
void ObjectPool::update(float deltaTime)
{
    for (Turret *turret : turrets)
    {
        turret->update(deltaTime);
    }

    for (Creep *creep : creeps)
    {
        creep->update(deltaTime);
    }

    for (Projectile *projectile : projectiles)
    {
        projectile->update(deltaTime);
    }

    for (TurretObserver *observer : observers)
    {
        observer->update();
    }
}

