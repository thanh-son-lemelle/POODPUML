#include "GameState.h"
#include "TurretFactory.h"
#include <QVBoxLayout>

GameState::GameState(QWidget *parent)
    : AppState(parent), updateTimer(new QTimer(this)), gameScene(new GameScene(this))
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(gameScene);
    setLayout(layout);

    Turret *normalTurret = TurretFactory::createTurret(TurretType::Normal, this);
    normalTurret->initialize(QVector2D(50, 50), 100.0f, 10);
    gameScene->addTurret(normalTurret);

    Turret *freezingTurret = TurretFactory::createTurret(TurretType::Freeze, this);
    freezingTurret->initialize(QVector2D(150, 150), 100.0f, 10);
    gameScene->addTurret(freezingTurret);

    // Connect the update timer to the update method
    connect(updateTimer, &QTimer::timeout, this, &GameState::update);

}

void GameState::onEnter()
{
    // Code to run when entering GameState
    // Start the update timer with a desired interval (e.g., 16 ms for ~60 FPS)
    updateTimer->start(16);
    // Initialize The Game Logic
}

void GameState::onExit()
{
    // Code to run when exiting GameState
    updateTimer->stop();
}

void GameState::update()
{
    // Update game logic here
    qDebug() << "Updating game state";
    // For example, move game objects, check collisions, etc.
    // ex: gameLogic->update
}
