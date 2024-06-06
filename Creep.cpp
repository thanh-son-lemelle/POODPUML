#include "Creep.h"
#include <QPixmap>
#include <QDebug>
#include "ObjectPool.h"

Creep::Creep(const QPixmap &pixmap, QObject *parent)
    : QObject(parent), QGraphicsPixmapItem(pixmap), health(100), speed(1.0f), isDead(false) {
}

Creep::~Creep() {
    qDebug() << "Creep destroyed.";

}

void Creep::initialize(const QVector2D& position) {
    this->position = position;
    setPos(position.toPointF());
    health = 100;
    qDebug() << "Creep initialized at position:" << position;
}

void Creep::update(float deltaTime) {

    move(deltaTime);
    handleCollisionProjectiles();
}

void Creep::takeDamage(int amount) {
    health -= amount;
    //qDebug() << "Creep took damage:" << amount << ", remaining health:" << health;
    if (health <= 0) {
        isDead = true;
    }
}

void Creep::move(float deltaTime) {
    // Example movement logic
    position += QVector2D(speed * deltaTime, 0); // Moves right
    setPos(position.toPointF());
    //qDebug() << "Creep moved to position:" << position;
    // if (position.x() > 100) { // Example condition for reaching the base
    //     handleCreepReachedBase();
    // }
}

void Creep::onDeath() {
    qDebug() << "Creep died.";
    // emit creepKilled();
    // eventDelegates.notifyCreepKilled();
    // handleCreepDeath();
}

void Creep::returnToPool() {
    qDebug() << "Creep returned to pool.";
    emit creepReturnToPool();
    eventDelegates.notifyCreepReturnToPool();
}

void Creep::handleCreepDeath() {
    qDebug() << "Handling creep death.";
    eventDelegates.notifyCreepKilled();
    returnToPool();
}

void Creep::handleCreepReachedBase() {
    qDebug() << "Handling creep reaching base.";
    emit creepReachedBase();
    eventDelegates.notifyCreepReachedBase();
    returnToPool();
}

void Creep::handleCollisionProjectiles()
{
    ObjectPool &objectPool = ObjectPool::getInstance();
    std::list<Projectile *> projectilesToRemove;
    for (Projectile *projectile : objectPool.getProjectiles())
    {
        if (projectile->getPosition().distanceToPoint(position) < 10)
        {
            takeDamage(projectile->getDamage());
            projectilesToRemove.push_back(projectile);
        }
    }

    for (Projectile *projectile : projectilesToRemove)
    {
        objectPool.removeProjectile(projectile);
    }
}

void Creep::draw(QPainter *painter) {
    painter->save();

    // Set the color and shape of the projectile
    painter->setBrush(Qt::red);
    painter->setPen(Qt::NoPen);

    // Draw the projectile as a circle at its current position
    painter->drawEllipse(position.toPointF(), 10, 10);

    // Restore the painter's state
    painter->restore();
}
