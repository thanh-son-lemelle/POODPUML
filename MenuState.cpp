#include "MenuState.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QToolButton>
#include <QLabel>
#include <QPixmap>
#include <QIcon>
#include <QSpacerItem>

MenuState::MenuState(QWidget *parent)
    : AppState(parent)
{
    // Create a label for the background image
    QLabel *backgroundLabel = new QLabel(this);
    QPixmap pix("C:\\POODPUML\\POODPUML\\assets\\Background.png");
    backgroundLabel->setPixmap(pix);
    backgroundLabel->setScaledContents(true); // Ensure the background scales to fit the window

    // Create a tool button to start the game and set its icon
    QToolButton *startGameButton = new QToolButton(this);
    QIcon buttonIcon("C:\\POODPUML\\POODPUML\\assets\\play_button.png");
    startGameButton->setIcon(buttonIcon);
    startGameButton->setIconSize(QSize(100, 100));
    startGameButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    startGameButton->setStyleSheet("border: none;"); // Remove the border

    // Connect the start game button to the slot function
    connect(startGameButton, &QToolButton::clicked, this, &MenuState::onStartGameButtonClicked);

    // Create a vertical layout for the menu
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(backgroundLabel); // Add the background label to the layout

    // Create a horizontal layout for the button and spacer
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum)); // Add expanding spacer to push button to the center

    // Add the button to the layout and center it horizontally
    buttonLayout->addWidget(startGameButton);
    buttonLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum)); // Add expanding spacer to push button to the center

    // Add the button layout to the vertical layout
    layout->addLayout(buttonLayout);

    // Set the layout for the menu
    setLayout(layout);
}

void MenuState::onEnter()
{
    // Code to run when entering MenuState
}

void MenuState::onExit()
{
    // Code to run when exiting MenuState
}

void MenuState::onStartGameButtonClicked()
{
    // Emit the startGame signal when the button is clicked
    emit startGame();
}
