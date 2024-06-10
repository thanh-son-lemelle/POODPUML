#include "Game.h"
#include "WaveManager.h"
#include "Turret.h"
#include "TurretFreeze.h"
#include "TurretRegular.h"
#include "TurretFactory.h"
#include "Music.h"
#include "Creep.h"
#include "ObjectPool.h"
#include <QTimer>
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>
#include <QVBoxLayout>

Game::Game(QWidget *parent)
    : QWidget(parent),
    waveManager(WaveManager::getInstance()),
    objectPool(ObjectPool::getInstance())
{
    setFixedSize(1479, 640);

    // Initialize the WaveManager
    waveManager.initialize();

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
    freezeTurretButton->setGeometry(width() - 190, 50, 180, 40);
    regularTurretButton->setGeometry(width() - 190, 100, 180, 40);
    // Connect buttons to their slots
    connect(freezeTurretButton, &QPushButton::clicked, this, &Game::selectFreezeTurret);
    connect(regularTurretButton, &QPushButton::clicked, this, &Game::selectRegularTurret);

    // Start the first wave
    waveManager.startNextWave();

    Music::getInstance()->playGameMusic();
}

void Game::update(float deltaTime) {
    objectPool.update(deltaTime);
    waveManager.update(deltaTime);
    checkForDeadCreeps();
    checkForProjectileOutOfBounds();
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
    painter.drawPixmap(0, 0, (width() - 200), height(), background);

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

        if (position.x() < (width() - 200)) { // Ensure clicks are within the game area
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

void Game::checkForDeadCreeps() {
    std::list<Creep *> creepsToRemove;
    for (auto creep : objectPool.getCreeps()) {
        if (creep->getIsDead()) {
            creepsToRemove.push_back(creep);
        }
    }

    for (auto creep : creepsToRemove) {
        objectPool.removeCreep(creep);
    }
}

void Game::checkForProjectileOutOfBounds() {
    std::list<Projectile *> projectilesToRemove;
    for (auto projectile : objectPool.getProjectiles()) {
        if (projectile->isOutOfBounds()) {
            projectilesToRemove.push_back(projectile);
        }
    }

    for (auto projectile : projectilesToRemove) {
        objectPool.removeProjectile(projectile);
    }
}