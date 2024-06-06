#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(835, 548); // set window size
    stackedWidget = new QStackedWidget(this);

    menuState = new MenuState(this);
    gameState = new GameState(this);

    stackedWidget->addWidget(menuState);
    stackedWidget->addWidget(gameState);

    setCentralWidget(stackedWidget);

    connect(menuState, &MenuState::startGame, this, &MainWindow::showGameState);

    showMenuState();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::switchState(AppState *newState)
{
    if (currentState)
        currentState->onExit();

    currentState = newState;
    stackedWidget->setCurrentWidget(currentState);
    currentState->onEnter();
}

void MainWindow::showGameState()
{
    switchState(gameState);
}

void MainWindow::showMenuState()
{
    switchState(menuState);
}
