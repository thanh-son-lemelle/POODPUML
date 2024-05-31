#ifndef CREEP_H
#define CREEP_H

#include <QObject>
#include <QVector2D>
#include <QGraphicsPixmapItem>
#include "Event.h"

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

signals:
    void creepKilled();
    void creepReachedBase();
    void creepReturnToPool();

protected:
    virtual void handleCreepDeath();
    virtual void handleCreepReachedBase();

private:
    int health;
    QVector2D position;
    float speed;
    Event creepKilledHandler;
    Event creepReachedBaseHandler;
    Event creepReturnToPoolHandler;
};

#endif // CREEP_H
