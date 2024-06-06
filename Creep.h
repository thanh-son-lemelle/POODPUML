#ifndef CREEP_H
#define CREEP_H

#include <QPainter>

#include <qvector2d.h>

class Creep {
private:
    int health;
    float speed;
    QVector2D position;

    static const int WIDTH = 400;  // Desired width of the creep image
    static const int HEIGHT = 400; // Desired height of the creep image

public:
    Creep(int hp, float spd, QVector2D pos);
    void update(float deltaTime);
    void takeDamage(int amount);
    void onKilled();
    void onReachedBase();

    void draw(QPainter &painter);

    //Getters
    QVector2D getPosition() const { return position; }
};

#endif // CREEP_H
