#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "appstate.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QTimer>

class GameState : public AppState
{
    Q_OBJECT

public:
    explicit GameState(QWidget *parent = nullptr);

    void onEnter() override;
    void onExit() override;

signals:
    void backToMenu();

private slots:
    void onBackToMenuButtonClicked();
    void update();
private:
    QTimer *updateTimer;

};

#endif // GAMESTATE_H
