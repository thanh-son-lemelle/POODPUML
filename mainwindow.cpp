#include "MainWindow.h"
#include "Game.h"
#include "Music.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QPalette>
#include <QBrush>
#include <QImage>
#include <QResizeEvent>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    setFixedSize(1479, 640);
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
    menuWidget->setAutoFillBackground(true);

    // Game widget setup

    stackedWidget->addWidget(menuWidget);
    stackedWidget->setCurrentWidget(menuWidget);

    connect(startButton, &QPushButton::clicked, this, &MainWindow::onStartGameClicked);
    connect(quitButton, &QPushButton::clicked, this, &QWidget::close);

    Music::getInstance()->playMenuMusic();
}

MainWindow::~MainWindow() {}

void MainWindow::onStartGameClicked() {
    gameWidget = new Game(this);
    stackedWidget->addWidget(gameWidget);
    stackedWidget->setCurrentWidget(gameWidget);
}

void MainWindow::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);

    QImage bgImage(":/MenuBackground.png");
    bgImage = bgImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(bgImage));
    menuWidget->setPalette(palette);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    QImage bgImage(":/MenuBackground.png");
    bgImage = bgImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(bgImage));
    menuWidget->setPalette(palette);
}