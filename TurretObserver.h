#ifndef TURRETOBSERVER_H
#define TURRETOBSERVER_H

#include "Turret.h"
#include "Creep.h"

class ObjectPool;

class TurretObserver
{

public:
    explicit TurretObserver(Turret *turret);
    ~TurretObserver();
    void update();
    void scanTarget();
    void checkForTargetInRange(std::list<Creep *> creeps);
    void removeTarget();
    void loseTarget();
    void onCreepLeftRange();
private:
    Turret *turret;
};

#endif // TURRETOBSERVER_H