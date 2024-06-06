#ifndef WAVEMANAGER_H
#define WAVEMANAGER_H

class WaveManager {
private:
    static WaveManager* instance;
    int currentWave;
    WaveManager() : currentWave(0) {}

public:
    static WaveManager* getInstance();
    void startNextWave();
};

#endif // WAVEMANAGER_H
