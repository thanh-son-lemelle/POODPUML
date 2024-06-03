#ifndef NORMALTURRET_H
#define NORMALTURRET_H

#include "turret.h"
#include "Projectile.h"

class NormalTurret : public Turret, public QGraphicsPixmapItem
{
public:
    explicit NormalTurret(QPixmap pixmap, QObject *parent = nullptr);
    void draw(QPainter *painter) override; // Implement draw method

    void fireProjectile() override; // Implement fireProjectile method
};

#endif // NORMALTURRET_H
