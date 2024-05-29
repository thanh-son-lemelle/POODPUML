#ifndef TURRET_H
#define TURRET_H

#include <QVector2D>
#include <QObject>
//#include "turretstate.h"
//#include "creep.h"

class Turret : public QObject {
    Q_OBJECT

private:
    QVector2D position;
    QVector2D direction;
    float range;
    int damage;
    //TurretState state;
    //Creep* target;

public:
    explicit Turret(QObject *parent = nullptr);
    void initialize(const QVector2D& position, float range, int damage);
    void update(float deltaTime);
    void rotate(const QVector2D& direction);
    void acquireTarget();
    void fireProjectile();
    //void onCreepEnteredRange(Creep* creep);
    //void onCreepLeftRange(Creep* creep);

    // Add any other necessary methods or member variables
};

#endif // TURRET_H
