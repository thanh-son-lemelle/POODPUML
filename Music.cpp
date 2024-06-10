#include "music.h"

Music *Music::instance = nullptr;

Music::Music(QObject *parent)
    : QObject(parent), isMuted(false)
{
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    menuTrack = QUrl("qrc:/menu_music.mp3");
    gameTrack = QUrl("qrc:/game_music.mp3");

    player->setSource(menuTrack);

    audioOutput->setVolume(0.5);
}

Music *Music::getInstance(QObject *parent)
{
    if (!instance)
        instance = new Music(parent);
    return instance;
}

void Music::playMenuMusic()
{
    player->setSource(menuTrack);
    player->play();
}

void Music::playGameMusic()
{
    player->setSource(gameTrack);
    player->play();
}

void Music::pause()
{
    player->pause();
}

void Music::toggleMute()
{
    isMuted = !isMuted;
    audioOutput->setMuted(isMuted);
}