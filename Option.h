#ifndef OPTION_H
#define OPTION_H

#include <QWidget>
#include <QSlider>

class Option : public QWidget
{
    Q_OBJECT

public:
    explicit Option(QWidget *parent = nullptr);

signals:
    void backToMenuClicked();

private slots:
    void onVolumeChanged(int volume);

private:
    QSlider *volumeSlider;
};

#endif // OPTION_H