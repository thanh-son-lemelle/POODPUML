#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QObject>
#include <QVector2D>
#include <QPainter>
#include "Creep.h"

class Projectile : public QObject
{
    Q_OBJECT

private:
    QVector2D position;
    Creep *target;
    int damage;
    int speed;

public:
    Projectile(QVector2D turretPosition, Creep *target, int damage, int speed, QObject *parent = nullptr);
    ~Projectile();

    void draw(QPainter *painter);
    void update();

signals:
    void hitTarget(Creep *target);
};
#endif // PROJECTILE_H