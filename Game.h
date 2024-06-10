#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QPushButton>
#include "WaveManager.h"
#include "ObjectPool.h"

class Game : public QWidget {
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    void update(float deltaTime);

private slots:
    void selectFreezeTurret();
    void selectRegularTurret();

private:
    void spawnCreep(Creep* creep);
    void addTurret(Turret* turret);
    void addRegularTurret(QVector2D position);//old function to add manualy in game regularturret
    void addFreezeTurret(QVector2D position);//old function to add manualy in game freezeturret

    void checkForDeadCreeps();


protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

    QTimer *timer;
    QPushButton *freezeTurretButton;
    QPushButton *regularTurretButton;
    enum TurretType { None, Freeze, Regular } selectedTurretType = None;

    WaveManager &waveManager;
    ObjectPool &objectPool = ObjectPool::getInstance();
};

#endif // GAME_H
