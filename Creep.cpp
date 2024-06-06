#include "Creep.h"

Creep::Creep(int hp, float spd) : health(hp), speed(spd) {}

void Creep::update(float deltaTime) {
    // Move logic
}

void Creep::takeDamage(int amount) {
    health -= amount;
    if (health <= 0) onKilled();
}

void Creep::onKilled() {
    // Logic when killed
}

void Creep::onReachedBase() {
    // Logic when reached base
}
