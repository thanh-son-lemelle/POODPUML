#ifndef OBJECTPOOL_H
#define OBJECTPOOL_H

#include <list>
#include <QObject>
#include "Projectile.h"
#include "Turret.h"
#include "TurretObserver.h"
#include "Creep.h"

class ObjectPool
{
public:
    // Delete copy constructor and assignment operator to prevent copying
    ObjectPool(const ObjectPool &) = delete;
    ObjectPool &operator=(const ObjectPool &) = delete;

    // Static method to get the single instance of the class
    static ObjectPool &getInstance();

    // Methods to add and remove projectiles
    void addProjectile(Projectile *projectile);
    void removeProjectile(Projectile *projectile);

    // Methods to add and remove turrets
    void addTurret(Turret *turret);
    void removeTurret(Turret *turret);

    // Methods to add and remove creeps
    void addCreep(Creep *creep);
    void removeCreep(Creep *creep);

    // Method to get all projectiles
    std::list<Projectile *> &getProjectiles();
    std::list<Turret *> &getTurrets();
    std::list<Creep *> &getCreeps();

private:
    // Private constructor and destructor
    ObjectPool();
    ~ObjectPool();

    // List to store projectiles
    std::list<Projectile *> projectiles;
    std::list<Turret *> turrets;
    std::list<Creep *> creeps;
    std::list<TurretObserver *> observers;
};

#endif // OBJECTPOOL_H
