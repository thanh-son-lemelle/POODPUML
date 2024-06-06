#include "WaveManager.h"

WaveManager* WaveManager::instance = nullptr;

WaveManager* WaveManager::getInstance() {
    if (!instance)
        instance = new WaveManager();
    return instance;
}

void WaveManager::startNextWave() {
    currentWave++;
    // Logic to start the next wave
}
