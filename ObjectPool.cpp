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


// Method to update all objects
void ObjectPool::update()
{
    for (Turret *turret : turrets)
    {
        turret->update(1);
    }

    for (Creep *creep : creeps)
    {
        creep->update(1);
    }

    for (Projectile *projectile : projectiles)
    {
        projectile->update(1);
    }
}

