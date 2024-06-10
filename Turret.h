#ifndef TURRET_H
#define TURRET_H

#include <QPainter>
#include <QVector2D>
#include <QObject>

class Creep;

class Turret: public QObject
{
    Q_OBJECT
protected:
    QVector2D position;
    float range;
    static const int WIDTH = 50;  // Desired width of the turret image
    static const int HEIGHT = 50; // Desired height of the turret image

    Creep *target;

public:
    virtual ~Turret() {}
    virtual void fireProjectile() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void draw(QPainter &painter) = 0;
    void initialize(QVector2D pos)
    {
        position = pos;
        target = nullptr;
        range = 200;
    }

    QVector2D getPosition() const { return position; }
    float getRange() const { return range; }
    Creep *getTarget() const { return target; }

    void setTarget(Creep *creep) { target = creep; }
};

#endif // TURRET_H
