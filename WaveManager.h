#ifndef WAVEMANAGER_H
#define WAVEMANAGER_H

#include <QObject>
#include <QTimer>
#include <QVector>
#include "Creep.h"
#include "ObjectPool.h"

class WaveManager : public QObject {
    Q_OBJECT

public:
    static WaveManager& getInstance() {
        static WaveManager instance;
        return instance;
    }

    void initialize();
    void startNextWave();
    void update(float deltaTime);

private slots:
    void spawnCreep();

private:
    WaveManager(QObject *parent = nullptr);
    ~WaveManager() = default;
    WaveManager(const WaveManager&) = delete;
    WaveManager& operator=(const WaveManager&) = delete;

    QVector<Creep*> creeps;
    QTimer* spawnTimer;
    int creepsPerWave;
    int creepsSpawned;
};

#endif // WAVEMANAGER_H
