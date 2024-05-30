#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QWidget>
#include <QList>
#include "turret.h"

//This class will be remplaced by ObjectPoolManager
class GameScene : public QWidget {
    Q_OBJECT

private:
    QList<Turret*> turrets;

public:
    explicit GameScene(QWidget *parent = nullptr);
    void addTurret(Turret *turret);
protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // GAMESCENE_H
