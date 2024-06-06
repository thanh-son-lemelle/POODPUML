#include "Projectile.h"

void Projectile::launch(QVector2D pos, QVector2D vel) {
    position = pos;
    velocity = vel;
}

void Projectile::update(float deltaTime) {
    // Update position based on velocity
}
