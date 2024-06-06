#include "Creep.h"

Creep::Creep(int hp, float spd, QVector2D pos) : health(hp), speed(spd), position(pos) {}

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

void Creep::draw(QPainter &painter) {
    QPixmap image(":/Creep.png");
    QPixmap scaledImage = image.scaled(WIDTH, HEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    painter.drawPixmap(position.toPointF(), scaledImage);
}
