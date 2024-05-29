#ifndef FREEZETURRET_H
#define FREEZETURRET_H

#include "turret.h"

class FreezeTurret : public Turret {
public:
    explicit FreezeTurret(QObject *parent = nullptr);
};

#endif // FREEZERTURRET_H
