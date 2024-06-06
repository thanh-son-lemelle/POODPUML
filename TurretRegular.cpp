#include "TurretRegular.h"
#include "Projectile.h"
#include <QPainter>
#include <QPixmap>

void TurretRegular::fireProjectile() {
    // Implementation of firing a regular projectile
}

void TurretRegular::update(float deltaTime) {
    // Update logic for RegularTurret
}

void TurretRegular::draw(QPainter &painter) {
    QPixmap image(":/RegularTurret.png");
    QPixmap scaledImage = image.scaled(WIDTH, HEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    painter.drawPixmap(position.toPointF(), scaledImage);
}
