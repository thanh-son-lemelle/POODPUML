#include "Option.h"
#include "Music.h"
#include <QVBoxLayout>
#include <QPushButton>

Option::Option(QWidget *parent) : QWidget(parent)
{
    volumeSlider = new QSlider(Qt::Horizontal, this);
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(Music::getInstance()->getVolume());

    QPushButton *backToMenuButton = new QPushButton("Back to Menu", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(volumeSlider);
    layout->addWidget(backToMenuButton);

    connect(volumeSlider, &QSlider::valueChanged, this, &Option::onVolumeChanged);
    connect(backToMenuButton, &QPushButton::clicked, this, &Option::backToMenuClicked);
}

void Option::onVolumeChanged(int volume)
{
    Music::getInstance()->setVolume(volume);
}