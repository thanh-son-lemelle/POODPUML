#ifndef GAME_H
#define GAME_H

#include <vector>
#include <QObject>
#include <QWidget>
#include <QTimer>
#include "ObjectPool.h"

class WaveManager;
class Turret;
class Creep;
class TurretFactory;

class Game : public QWidget {
    Q_OBJECT

private:
    std::vector<Turret*> turrets;
    std::vector<Creep*> creeps;
    WaveManager* waveManager;
    QTimer* timer;

public:
    Game(QWidget *parent = nullptr);
    void update(float deltaTime);
    void spawnCreep(Creep* creep);
    void addTurret(Turret* turret);
    void addRegularTurret(QVector2D position);
    void addFreezeTurret(QVector2D position);

    ObjectPool &objectPool = ObjectPool::getInstance();

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // GAME_H
