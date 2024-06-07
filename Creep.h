#ifndef CREEP_H
#define CREEP_H

#include <QPainter>

#include <qvector2d.h>

class Creep {
private:
    int health;
    float speed;
    QVector2D position;
    bool isDead = false;

    static const int WIDTH = 50;  // Desired width of the creep image
    static const int HEIGHT = 50; // Desired height of the creep image

public:
    Creep(int hp, float spd, QVector2D pos);
    void update(float deltaTime);
    void takeDamage(int amount);
    void move(float deltaTime);
    void onKilled();
    void onReachedBase();
    void onCollisionWithProjectile();

    void draw(QPainter &painter);

    //Getters
    QVector2D getPosition() const { return position; }
    bool getIsDead() const { return isDead; }
};

#endif // CREEP_H
