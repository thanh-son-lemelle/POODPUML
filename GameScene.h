#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QWidget>
#include <QList>
#include "turret.h"
#include "Creep.h"

//This class will be remplaced by ObjectPoolManager
class GameScene : public QWidget {
    Q_OBJECT

private:
    QList<Turret*> turrets;
    QList<Creep*> creeps;

public:
    explicit GameScene(QWidget *parent = nullptr);
    void addTurret(Turret *turret);
    void addCreep(Creep *creep);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // GAMESCENE_H
