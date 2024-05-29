#include "turret.h"
#include <cmath>
#include <iostream>


Turret::Turret(QObject *parent)
    : QObject(parent), position(0, 0), direction(0, 1), range(100.0f) , damage(0)
{} //, state(TurretState::Idle), target(nullptr)

void Turret::initialize(const QVector2D& position, float range, int damage) {
    this->position = position;
    this->range = range;
    this->damage = damage;
    //this->state = TurretState::Idle;
    //this->target = nullptr;
    }

    /*
void Turret::update(float deltaTime) {
    switch (state) {
    case TurretState::Idle:
        acquireTarget();
        break;
    case TurretState::AcquiringTarget:
        // Implement target acquisition logic
        break;
    case TurretState::Firing:
        fireProjectile();
        state = TurretState::Cooldown;
        break;
    case TurretState::Cooldown:
        // Implement cooldown logic
        state = TurretState::Idle;
        break;
    }
}

void Turret::rotate(const QVector2D& direction) {
    this->direction = direction.normalized();
}

void Turret::acquireTarget() {
    // Simple logic to acquire a target (this needs to be expanded)
    std::vector<Creep*> creepsInRange; // This would normally be populated by the game
    for (Creep* creep : creepsInRange) {
        float distance = (creep->position - position).length();
        if (distance <= range) {
            target = creep;
            state = TurretState::Firing;
            break;
        }
    }
}

void Turret::fireProjectile() {
    if (target) {
        std::cout << "Firing at target at position (" << target->position.x() << ", " << target->position.y() << ")" << std::endl;
        // Implement projectile firing logic
    }
}

void Turret::onCreepEnteredRange(Creep* creep) {
    // Handle logic when a creep enters range
    // This could involve adding the creep to a list of targets
}

void Turret::onCreepLeftRange(Creep* creep) {
    // Handle logic when a creep leaves range
    if (target == creep) {
        target = nullptr;
        state = TurretState::Idle;
    }
    // This could involve removing the creep from a list of targets
}
*/
