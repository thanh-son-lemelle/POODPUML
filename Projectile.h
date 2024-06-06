#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QObject>
#include <QVector2D>
#include <QPainter>
#include "Creep.h"
#include <QGraphicsEllipseItem>

enum class ProjectileType
{
    Normal,
    Freeze
};

class Projectile : public QObject
{
    Q_OBJECT

private:
    QVector2D position;
    Creep *target;
    int damage;
    int speed;
    ProjectileType type;

public:
    Projectile(QVector2D turretPosition, Creep *target, int damage, int speed, QObject *parent = nullptr, ProjectileType type = ProjectileType::Normal);
    ~Projectile();

    void draw(QPainter *painter);
    void update();

    void setTarget(Creep *target) { this->target = target; }

    ProjectileType getType() const { return type; }
    QVector2D getPosition() const { return position; }
    int getDamage() const { return damage; }
    Creep *getTarget() const { return target; }
};
#endif // PROJECTILE_H