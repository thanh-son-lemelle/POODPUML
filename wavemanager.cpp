#include "wavemanager.h"
#include <QDebug>
#include <mutex>

std::unique_ptr<WaveManager> WaveManager::instance;
std::once_flag WaveManager::initInstanceFlag;

WaveManager& WaveManager::getInstance() {
            std::call_once(initInstanceFlag, [](){
        instance.reset(new WaveManager());
    });
    return *instance;
}
WaveManager::WaveManager(QObject*parent): QObject(parent){
    // Initialize object here
}

void WaveManager::startNextWave() {
    qDebug() << "Starting the next wave.";
    // Implementation for starting the next wave
}

void WaveManager::spawnWave() {
    qDebug() << "Spawning a new wave.";
    // Implementation for spawning a new wave
}

void WaveManager::onLastWaveCleared() {
    qDebug() << "Last wave cleared.";
    emit lastWaveCleared();
    // Additional logic when the last wave is cleared
}
