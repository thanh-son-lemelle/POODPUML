#include "NormalTurret.h"

NormalTurret::NormalTurret(QObject *parent)
    : Turret(parent) {
    // Initialize specific attributes for a normal turret
}

void NormalTurret::draw(QPainter *painter) {
    painter->setBrush(Qt::blue);
    painter->drawEllipse(getPosition().toPointF(), 10, 10); // Draw a circle representing the turret
}
