#include <QTimer>
#include "Creep.h"
#include "ObjectPool.h"
#include "Path.h"

Creep::Creep(int hp, float spd, QVector2D pos)
    : health(hp), speed(spd), position(pos), waypoints(Path::getWaypoints()), currentWaypointIndex(0) {}

void Creep::initialize(QVector2D pos) {
    position = pos;
        currentWaypointIndex = 0;
}

void Creep::update(float deltaTime) {
    move(deltaTime);
    onCollisionWithProjectile();
    checkLife();
}

void Creep::move(float deltaTime) {
    // Move logic
    if (currentWaypointIndex < waypoints.size()) {
        QVector2D target = waypoints[currentWaypointIndex];
        QVector2D direction = (target - position).normalized();
        position += direction * speed * deltaTime;

        // Check if reached the waypoint
        if ((target - position).length() < speed * deltaTime) {
            currentWaypointIndex++;
        }
    } else {
        onReachedBase();
    }
}

void Creep::takeDamage(int amount) {
    health -= amount;  
}

void Creep::onReachedBase() {
    // Logic when reached base
}

void Creep::draw(QPainter &painter) {
    QPixmap image(":/Creep.png");
    QPixmap scaledImage = image.scaled(WIDTH, HEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    painter.drawPixmap(position.toPointF(), scaledImage);
}

void Creep::onCollisionWithProjectile()
{
    ObjectPool &objectPool = ObjectPool::getInstance();
    std::list<Projectile *> projectilesToRemove;
    for (Projectile *projectile : objectPool.getProjectiles())
    {
        if (projectile->getPosition().distanceToPoint(position) < 20)
        {
            // Add logic for when a projectile collides with a creep
            projectile->applyEffect(this);
            projectilesToRemove.push_back(projectile);
        }
    }

    for (Projectile *projectile : projectilesToRemove)
    {
        objectPool.removeProjectile(projectile);
    }
}

void Creep::freeze(int duration)
{
    speed /= 2;
    int durationInMilliseconds = duration * 1000;
    QTimer::singleShot(durationInMilliseconds, this, [this] { speed *= 2; });
}

void Creep::checkLife()
{
    if (health <= 0)
    {
        isDead = true;
    }
}