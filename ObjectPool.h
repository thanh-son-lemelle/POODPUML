#ifndef OBJECTPOOL_H
#define OBJECTPOOL_H

#include <list>
#include "Projectile.h"

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

    // Method to get all projectiles
    std::list<Projectile *> &getProjectiles();

private:
    // Private constructor and destructor
    ObjectPool();
    ~ObjectPool();

    // List to store projectiles
    std::list<Projectile *> projectiles;
};

#endif // OBJECTPOOL_H
