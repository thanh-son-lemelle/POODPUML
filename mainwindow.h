#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "appstate.h"
#include "menustate.h"
#include "gamestate.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;
    AppState *currentState;
    MenuState *menuState;
    GameState *gameState;

    void switchState(AppState *newState);

private slots:
    void showGameState();
    void showMenuState();
};

#endif // MAINWINDOW_H
