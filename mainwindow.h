#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>
#include "Game.h"

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onStartGameClicked();

private:
    QStackedWidget *stackedWidget;
    QWidget *menuWidget;
    Game *gameWidget;
};

#endif // MAINWINDOW_H
