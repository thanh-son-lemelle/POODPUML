#include "WaveManager.h"
#include <QDebug>

WaveManager::WaveManager(QObject *parent)
    : QObject(parent), spawnTimer(new QTimer(this)), creepsPerWave(10), creepsSpawned(0) {
    connect(spawnTimer, &QTimer::timeout, this, &WaveManager::spawnCreep);
}

void WaveManager::initialize() {
    // Additional initialization if needed
}

void WaveManager::startNextWave() {
    creepsSpawned = 0;
    spawnTimer->start(1000); // Spawn a creep every second
}

void WaveManager::spawnCreep() {
    if (creepsSpawned >= creepsPerWave) {
        spawnTimer->stop();
        return;
    }

    Creep* creep = new Creep(100, 50.0f, QVector2D(225, -25));
    ObjectPool::getInstance().addCreep(creep);
    creepsSpawned++;
}

void WaveManager::update(float deltaTime) {
}
