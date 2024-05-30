#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "appstate.h"
#include <QPushButton>
#include <QVBoxLayout>

class MenuState : public AppState
{
    Q_OBJECT

public:
    explicit MenuState(QWidget *parent = nullptr);

    void onEnter() override;
    void onExit() override;

signals:
    void startGame();

private slots:
    void onStartGameButtonClicked();
};

#endif // MENUSTATE_H
