#ifndef TURRET_H
#define TURRET_H

#include <QVector2D>
#include <QObject>
#include <QPainter>

class Turret : public QObject {
    Q_OBJECT

protected:
    QVector2D position;
    QVector2D direction;
    float range;
    int damage;

public:
    explicit Turret(QObject *parent = nullptr);
    void initialize(const QVector2D& position, float range, int damage);
    virtual void draw(QPainter *painter) = 0; // Pure virtual draw method

    // Getter and setter for position
    QVector2D getPosition() const;
    void setPosition(const QVector2D& pos);
};

#endif // TURRET_H
