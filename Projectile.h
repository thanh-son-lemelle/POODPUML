#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QVector2D>
#include <QPainter>

class Creep;

class Projectile {
protected:
    QVector2D position;
    QVector2D direction;
    int speed;
    int damage;
    Creep *target;

public:
    Projectile(QVector2D pos, int spd, int dmg, Creep *targ);
    void update(float deltaTime);
    virtual void applyEffect(Creep* target) = 0;

    virtual void draw(QPainter &painter) = 0;

    // Getters
    QVector2D getPosition() const { return position; }
    int getDamage() const { return damage; }
    Creep *getTarget() const { return target; }
};

#endif // PROJECTILE_H
