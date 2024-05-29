#ifndef NORMALTURRET_H
#define NORMALTURRET_H

#include "turret.h"

class NormalTurret : public Turret {
public:
    explicit NormalTurret(QObject *parent = nullptr);
};

#endif // NORMALTURRET_H
