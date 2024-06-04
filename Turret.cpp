#include "Turret.h"

Turret::Turret(QObject *parent)
    : QObject(parent), position(0, 0), range(100.0f), damage(0), target(nullptr), state{TurretState::Idle} // direction(0, 1)
{}
void Turret::initialize(const QVector2D& position, float range, int damage, int projectileSpeed) {
    this->position = position;
    this->range = range;
    this->damage = damage;
    this->projectileSpeed = projectileSpeed;
}

QVector2D Turret::getPosition() const {
    return position;
}

void Turret::setPosition(const QVector2D& pos) {
    position = pos;
}
