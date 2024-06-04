#ifndef APPSTATE_H
#define APPSTATE_H

#include <QWidget>

class AppState : public QWidget
{
    Q_OBJECT

public:
    explicit AppState(QWidget *parent = nullptr) : QWidget(parent) {}

    virtual ~AppState() {}

    virtual void onEnter() = 0;
    virtual void onExit() = 0;
};

#endif // APPSTATE_H
