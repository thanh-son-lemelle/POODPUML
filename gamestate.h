#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "appstate.h"
#include <QPushButton>
#include <QVBoxLayout>

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
};

#endif // GAMESTATE_H
