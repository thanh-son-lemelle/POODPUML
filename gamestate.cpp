#include "gamestate.h"

GameState::GameState(QWidget *parent)
    : AppState(parent)
, updateTimer(new QTimer(this))
{
    QPushButton *backToMenuButton = new QPushButton("Back to Menu", this);
    connect(backToMenuButton, &QPushButton::clicked, this, &GameState::onBackToMenuButtonClicked);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(backToMenuButton);
    setLayout(layout);

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

void GameState::onBackToMenuButtonClicked()
{
    emit backToMenu();
}

void GameState::update()
{
    // Update game logic here
    qDebug() << "Updating game state";
    // For example, move game objects, check collisions, etc.
    // ex: gameLogic->update
}
