#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QVector2D>

class Creep;

class Projectile {
protected:
    QVector2D position;
    QVector2D velocity;
    int damage;

public:
    void launch(QVector2D pos, QVector2D vel);
    void update(float deltaTime);
    virtual void applyEffect(Creep* target) = 0;
};

#endif // PROJECTILE_H
