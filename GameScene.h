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
public:
    explicit GameScene(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // GAMESCENE_H
