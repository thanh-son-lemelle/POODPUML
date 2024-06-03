#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:\\POODPUML\\POODPUML\\assets\\Background.png");
    ui->label->setPixmap(pix);
    QIcon buttonIcon("C:\\POODPUML\\POODPUML\\assets\\play_button.png");
    ui->toolButton->setIcon(buttonIcon);
    ui->toolButton->setIconSize(QSize(100, 100));

}

MainWindow::~MainWindow()
{
    delete ui;
}
