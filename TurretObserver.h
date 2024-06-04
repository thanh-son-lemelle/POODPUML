#ifndef TURRETOBSERVER_H
#define TURRETOBSERVER_H

#include <QObject>
#include "Turret.h"
#include "Creep.h"

class TurretObserver : public QObject
{
    Q_OBJECT

public:
    explicit TurretObserver(Turret *turret, QObject *parent = nullptr);

public slots:
    void onCreepMoved(Creep *creep);

private:
    Turret *turret;
};

#endif // TURRETOBSERVER_H