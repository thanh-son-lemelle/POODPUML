#include "TurretFreeze.h"
#include "Projectile.h"
#include <QPainter>
#include <QPixmap>

void TurretFreeze::fireProjectile() {
    // Implementation of firing a freezing projectile
}

void TurretFreeze::update(float deltaTime) {
    // Update logic for FreezeTurret
}

void TurretFreeze::draw(QPainter &painter) {
    QPixmap image(":/FreezeTurret.png");
    QPixmap scaledImage = image.scaled(WIDTH, HEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    // Center the image on the position
    QPointF centeredPosition = position.toPointF() - QPointF(scaledImage.width() / 2, scaledImage.height() / 2);
    painter.drawPixmap(centeredPosition, scaledImage);
}
