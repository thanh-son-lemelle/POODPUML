#include "Turret.h"

Turret::Turret(QPixmap pixmap, QObject *parent)
    : QObject(parent), QGraphicsPixmapItem(pixmap), position(0, 0), range(100.0f), damage(0), target(nullptr) {} // direction(0, 1)

void Turret::initialize(const QVector2D& position, float range, int damage, int projectileSpeed) {
    this->position = position;
    this->range = range;
    this->damage = damage;
    this->projectileSpeed = projectileSpeed;
    setPos(this->position.toPointF());
}

QVector2D Turret::getPosition() const {
    return position;
}

void Turret::setPosition(const QVector2D& pos) {
    position = pos;
}
