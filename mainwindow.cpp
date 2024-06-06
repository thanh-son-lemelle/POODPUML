#include "MainWindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    setFixedSize(800, 600);

    stackedWidget = new QStackedWidget(this);

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

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(stackedWidget);
    setLayout(mainLayout);

    connect(startButton, &QPushButton::clicked, this, &MainWindow::onStartGameClicked);
    connect(quitButton, &QPushButton::clicked, this, &QWidget::close);
}

void MainWindow::onStartGameClicked() {
    stackedWidget->setCurrentWidget(gameWidget);
}
