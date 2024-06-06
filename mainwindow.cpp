#include "MainWindow.h"
#include "Game.h"
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    // Menu widget setup
    menuWidget = new QWidget(this);
    QPushButton *startButton = new QPushButton("Start Game", menuWidget);
    QPushButton *optionsButton = new QPushButton("Options", menuWidget);
    QPushButton *quitButton = new QPushButton("Quit", menuWidget);

    QVBoxLayout *menuLayout = new QVBoxLayout(menuWidget);
    menuLayout->addWidget(startButton);
    menuLayout->addWidget(optionsButton);
    menuLayout->addWidget(quitButton);
    menuWidget->setLayout(menuLayout);

    // Game widget setup
    gameWidget = new Game(this);

    stackedWidget->addWidget(menuWidget);
    stackedWidget->addWidget(gameWidget);
    stackedWidget->setCurrentWidget(menuWidget);

    connect(startButton, &QPushButton::clicked, this, &MainWindow::onStartGameClicked);
    connect(quitButton, &QPushButton::clicked, this, &QWidget::close);
}

MainWindow::~MainWindow() {}

void MainWindow::onStartGameClicked() {
    stackedWidget->setCurrentWidget(gameWidget);
}
