#ifndef OBJECTPOOL_H
#define OBJECTPOOL_H

#include <list>
#include "Turret.h"
#include "Creep.h"

class ObjectPool
{
public:
    // Delete copy constructor and assignment operator to prevent copying
    ObjectPool(const ObjectPool &) = delete;
    ObjectPool &operator=(const ObjectPool &) = delete;

    // Static method to get the single instance of the class
    static ObjectPool &getInstance();

    // Methods to add and remove turrets
    void addTurret(Turret *turret);
    void removeTurret(Turret *turret);

    // Methods to add and remove creeps
    void addCreep(Creep *creep);
    void removeCreep(Creep *creep);

    // Method to get all projectiles, turrets, creeps, and observers
    std::list<Turret *> &getTurrets();
    std::list<Creep *> &getCreeps();

    // Method to update all objects
    void update();

private:
    // Private constructor and destructor
    ObjectPool();
    ~ObjectPool();

    // List to store projectiles, turrets, creeps, and observers
    std::list<Turret *> turrets;
    std::list<Creep *> creeps;
};

#endif // OBJECTPOOL_H
