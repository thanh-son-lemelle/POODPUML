#ifndef CREEP_H
#define CREEP_H

#include <qvector2d.h>

class Creep {
private:
    int health;
    float speed;
    QVector2D position;

public:
    Creep(int hp, float spd);
    void update(float deltaTime);
    void takeDamage(int amount);
    void onKilled();
    void onReachedBase();
};

#endif // CREEP_H
