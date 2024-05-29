#include "turret.h"

Turret::Turret(QObject *parent)
    : QObject(parent), position(0, 0), direction(0, 1), range(100.0f), damage(0) {}

void Turret::initialize(const QVector2D& position, float range, int damage) {
    this->position = position;
    this->range = range;
    this->damage = damage;
}

QVector2D Turret::getPosition() const {
    return position;
}

void Turret::setPosition(const QVector2D& pos) {
    position = pos;
}
