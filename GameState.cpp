#include "GameState.h"
#include "TurretFactory.h"
#include <QVBoxLayout>
#include "Creep.h"

GameState::GameState(QWidget *parent)
    : AppState(parent), updateTimer(new QTimer(this)), gameScene(new GameScene(this)), score(0)
{
    ObjectPool &objectPool = ObjectPool::getInstance();
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(gameScene);
    setLayout(layout);

    // Testing Purposes
    Turret *normalTurret = TurretFactory::createTurret(TurretType::Normal, this);
    normalTurret->initialize(QVector2D(75, 130), 300.0f, 10, 5);
    gameScene->addTurret(normalTurret);

    Turret *freezingTurret = TurretFactory::createTurret(TurretType::Freeze, this);
    freezingTurret->initialize(QVector2D(700, 500), 300.0f, 2, 20);
    gameScene->addTurret(freezingTurret);

    objectPool.addTurret(normalTurret);
    objectPool.addTurret(freezingTurret);
    // End Testing Purposes

    // Simulating what does wave manager do
    QPixmap pixmap(":/images/assets/creep.png");
    Creep *creep = new Creep(pixmap);
    creep->initialize(QVector2D(50, 400));
    objectPool.addCreep(creep);
    gameScene->addCreep(creep);

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
    //qDebug() << "Updating game state";
    ObjectPool &objectPool = ObjectPool::getInstance();
    for (Projectile *projectile : objectPool.getProjectiles())
    {
        projectile->update();
    }
    for (Creep *creep : objectPool.getCreeps())
    {
        creep->update(1);
    }
    for (TurretObserver *observer : objectPool.getObservers())
    {
        observer->update();
    }

    for (Turret *turret : objectPool.getTurrets())
    {
        turret->update();
    }
    gameScene->update();
    // For example, move game objects, check collisions, etc.
    // ex: gameLogic->update
}
