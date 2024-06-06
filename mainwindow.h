#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

class Game;

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    QStackedWidget* stackedWidget;
    QWidget* menuWidget;
    Game* gameWidget;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onStartGameClicked();
};

#endif // MAINWINDOW_H
