#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "appstate.h"
#include "GameScene.h"
#include "ObjectPool.h"
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

    private slots : void update();

private:
    QTimer *updateTimer;
    GameScene *gameScene;
    ObjectPool *objectPool;
};

#endif // GAMESTATE_H
