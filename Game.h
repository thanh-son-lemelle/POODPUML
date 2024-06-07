#ifndef GAME_H
#define GAME_H

#include <vector>
#include <QPushButton>
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
    QPushButton* freezeTurretButton;
    QPushButton* regularTurretButton;
    enum TurretType { None, Freeze, Regular } selectedTurretType;

public:
    Game(QWidget *parent = nullptr);
    void update(float deltaTime);
    void spawnCreep(Creep* creep);
    void addTurret(Turret* turret);
    void addRegularTurret(QVector2D position);//old function to add manualy in game regularturret
    void addFreezeTurret(QVector2D position);//old function to add manualy in game freezeturret

    ObjectPool &objectPool = ObjectPool::getInstance();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void selectFreezeTurret();
    void selectRegularTurret();
};

#endif // GAME_H
