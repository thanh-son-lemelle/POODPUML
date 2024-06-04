#ifndef CREEP_H
#define CREEP_H

#include <QObject>
#include <QVector2D>
#include <QGraphicsPixmapItem>
#include "EventCreepDelegates.h"

class Creep : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    explicit Creep(const QPixmap &pixmap, QObject *parent = nullptr);
    void initialize(const QVector2D& position);
    void update(float deltaTime);
    void takeDamage(int amount);
    void move(float deltaTime);
    void onDeath();
    void returnToPool();

    QVector2D getPosition() const { return position; }

signals:
    void creepKilled();
    void creepReachedBase();
    void creepReturnToPool();
    void moved(Creep *creep);

protected:
    virtual void handleCreepDeath();
    virtual void handleCreepReachedBase();
    void handleCollisionProjectiles();

private:
    int health;
    QVector2D position;
    float speed;
    EventCreepDelegates eventDelegates;
    
};

#endif // CREEP_H
