#ifndef MUSIC_H
#define MUSIC_H

#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>

class Music : public QObject
{
    Q_OBJECT

public:
    static Music *getInstance(QObject *parent = nullptr);
    void playMenuMusic();
    void playGameMusic();
    void pause();
    void toggleMute();

    int getVolume() const { return audioOutput->volume() * 100; }
    void setVolume(int volume) { audioOutput->setVolume(volume / 100.0); }

private:
    explicit Music(QObject *parent = nullptr);
    Music(const Music &) = delete;
    Music &operator=(const Music &) = delete;

    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    QUrl menuTrack;
    QUrl gameTrack;
    bool isMuted;

    static Music *instance;
};

#endif // MUSIC_H