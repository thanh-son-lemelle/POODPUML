#include "gamestate.h"

GameState::GameState(QWidget *parent)
    : AppState(parent)
{
    QPushButton *backToMenuButton = new QPushButton("Back to Menu", this);
    connect(backToMenuButton, &QPushButton::clicked, this, &GameState::onBackToMenuButtonClicked);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(backToMenuButton);
    setLayout(layout);
}

void GameState::onEnter()
{
    // Code to run when entering GameState
}

void GameState::onExit()
{
    // Code to run when exiting GameState
}

void GameState::onBackToMenuButtonClicked()
{
    emit backToMenu();
}
