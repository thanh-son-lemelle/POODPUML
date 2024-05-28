#ifndef WAVEMANAGER_H
#define WAVEMANAGER_H

#include <QObject>
#include <memory>
#include <mutex>
#include "Event.h"
#include "ObjectPoolManager.h"

class WaveManager : QObject

{
    Q_OBJECT
public:
    static WaveManager& getInstance();
    void startNextWave();
    void spawnWave();
    void onLastWaveCleared();

signals:
    void lastWaveCleared();

private:
    explicit WaveManager(QObject *parent = nullptr);
    ~WaveManager() = default;
    WaveManager(const WaveManager&) = delete;

    static std::unique_ptr<WaveManager> instance;
    static std::once_flag initInstanceFlag;

    event lastWaveClearedEvent;
    ObjectPoolManager objectPoolManager;
};

#endif // WAVEMANAGER_H
