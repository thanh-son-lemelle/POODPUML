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
#include <QMouseEvent>
#include <QVBoxLayout>

Game::Game(QWidget *parent) : QWidget(parent), waveManager(WaveManager::getInstance()) {
    setFixedSize(1000, 600);

    //Spawn creeps test purposes
    Creep* creep = new Creep(100, 1.0f, QVector2D(100, 100));
    spawnCreep(creep);

    // Create a timer to update the game
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this]() {
        update(1.0f / 60.0f); // Assuming 60 FPS
        QWidget::update(); // Update the QWidget to trigger a repaint
    });
    timer->start(16); // Approximately 60 FPS

    // Create buttons
    freezeTurretButton = new QPushButton("add Freeze Turret", this);
    regularTurretButton = new QPushButton("add Regular Turret", this);
    // Set button geometry
    freezeTurretButton->setGeometry(810, 50, 180, 40);
    regularTurretButton->setGeometry(810, 100, 180, 40);
    // Connect buttons to their slots
    connect(freezeTurretButton, &QPushButton::clicked, this, &Game::selectFreezeTurret);
    connect(regularTurretButton, &QPushButton::clicked, this, &Game::selectRegularTurret);
}

void Game::update(float deltaTime) {
    for (auto turret : objectPool.getTurrets()) {
        turret->update(deltaTime);
    }
    for (auto creep : objectPool.getCreeps()) {
        creep->update(deltaTime);
    }
    for (auto projectile : objectPool.getProjectiles()) {
        projectile->update(deltaTime);
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
    for (auto projectile : objectPool.getProjectiles()) {
        projectile->draw(painter);
    }
}

void Game::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        QVector2D position(event->pos());

        if (position.x() < 800) { // Ensure clicks are within the game area
            Turret* turret = nullptr;

            switch (selectedTurretType) {
            case Freeze:
                addFreezeTurret(position);
                break;
            case Regular:
                addRegularTurret(position);
                break;
            case None:
            default:
                break;
            }

            if (turret) {
                turret->initialize(position);
                addTurret(turret);
                selectedTurretType = None; // Reset turret selection
            }
        }
    }
}

void Game::selectFreezeTurret() {
    selectedTurretType = Freeze;
}

void Game::selectRegularTurret() {
    selectedTurretType = Regular;
}
