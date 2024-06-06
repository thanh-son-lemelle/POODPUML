#include "Game.h"
#include "WaveManager.h"
#include "Turret.h"
#include "TurretFreeze.h"
#include "TurretRegular.h"
#include "TurretFactory.h"
#include "Creep.h"
#include <QTimer>
#include <QPainter>
#include <QPixmap>

Game::Game(QWidget *parent) : QWidget(parent), waveManager(WaveManager::getInstance()) {
    setFixedSize(800, 600);

    // Example positions for turrets
    QVector2D regularTurretPosition(0, 0);
    QVector2D freezeTurretPosition(300, 400);

    // Add turrets to the game scene
    addRegularTurret(regularTurretPosition);
    addFreezeTurret(freezeTurretPosition);

    //Spawn creeps
    Creep* creep = new Creep(100, 1.0f, QVector2D(100, 100));
    spawnCreep(creep);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this]() {
        update(1.0f / 60.0f); // Assuming 60 FPS
        QWidget::update(); // Update the QWidget to trigger a repaint
    });
    timer->start(16); // Approximately 60 FPS
}

void Game::update(float deltaTime) {
    for (auto turret : objectPool.getTurrets()) {
        turret->update(deltaTime);
    }
    for (auto creep : objectPool.getCreeps()) {
        creep->update(deltaTime);
    }
    // Additional game logic
}

void Game::spawnCreep(Creep* creep) {
    objectPool.addCreep(creep);
}

void Game::addTurret(Turret* turret) {
    objectPool.addTurret(turret);
}

void Game::addRegularTurret(QVector2D position) {
    TurretFactory* factory = new TurretRegularFactory();
    Turret* turret = factory->createTurret(position);
    addTurret(turret);
    delete factory; // clean up factory
}

void Game::addFreezeTurret(QVector2D position) {
    TurretFactory* factory = new TurretFreezeFactory();
    Turret* turret = factory->createTurret(position);
    addTurret(turret);
    delete factory;
}

void Game::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    // Draw background image
    QPixmap background(":/Background.png");
    painter.drawPixmap(0, 0, width(), height(), background);

    // Draw game elements (turrets, creeps, etc.)
    for (auto turret : objectPool.getTurrets()) {
        turret->draw(painter);
    }
    for (auto creep : objectPool.getCreeps()) {
        creep->draw(painter);
    }
}
