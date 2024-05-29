#include "FreezeTurret.h"

FreezeTurret::FreezeTurret(QObject *parent)
    : Turret(parent) {
    // Initialize specific attributes for a freezing turret
}

void FreezeTurret::draw(QPainter *painter) {
    painter->setBrush(Qt::cyan);
    painter->drawEllipse(getPosition().toPointF(), 10, 10);
}
