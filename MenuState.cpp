#include "MenuState.h"

MenuState::MenuState(QWidget *parent)
    : AppState(parent)
{
    QPushButton *startGameButton = new QPushButton("Start Game", this);
    connect(startGameButton, &QPushButton::clicked, this, &MenuState::onStartGameButtonClicked);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(startGameButton);
    setLayout(layout);
}

void MenuState::onEnter()
{
    // Code to run when entering MenuState
}

void MenuState::onExit()
{
    // Code to run when exiting MenuState
}

void MenuState::onStartGameButtonClicked()
{
    emit startGame();
}
