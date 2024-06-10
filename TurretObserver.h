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
    void onCreepEnteredRange(ObjectPool &objectPool);
    void onCreepLeftRange(ObjectPool &objectPool);

private:
    Turret *turret;
};

#endif // TURRETOBSERVER_H