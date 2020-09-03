#include "mainwindow.h"
#include <QActionGroup>
#include <QObject>





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)


{

    resize(800,600);
    setWindowTitle("Quiz");


    mnuBar = new QMenuBar;
    pmnuGame = new QMenu("Game");
    pmnuView = new QMenu("View");
    pmnuSettings = new QMenu("Settings");
    pmnuHelp = new QMenu("Help");

    //Game menu  variables declaring

    pmnuSubMenuNewGame = new QMenu("New Game");//aq wavshale parent(meore parametri)
    pSubMenuAllGamesAction = new QAction("All Games(Logic,Math,Memory and Verbal)",pmnuSubMenuNewGame);
    pSubMenuLogicAction = new QAction("Logic Only",pmnuSubMenuNewGame);
    pSubMenuMathAction  = new QAction("Math Only",pmnuSubMenuNewGame);
    pSubMenuMemoryAction = new QAction("Memory Only",pmnuSubMenuNewGame);
    PSubMenuVerbalAction = new QAction("Verbal Only",pmnuSubMenuNewGame);
    pSubMenuCustomAction = new QAction("Custom Game Selection...",pmnuSubMenuNewGame);

    pPauseGameAction = new QAction("Pause Game");
    pEndGameAction = new QAction("End Game");


    // View menu  variables declaring
    pmnuToolbar = new QMenu("Toolbar");
    pShowAction = new QAction("Show");
    pmnuSubMenuOrientation = new QMenu("Orientation");
    pSubMenuHorizontal = new QAction("Horizontal");
    pSubMenuVertical = new QAction("Vertical");
    pFullscreenAction = new QAction("FullScreen");


    //Settings menu  variables declaring
    pPreferencesACtion = new QAction("Preferences");



    //Help menu  variables declaring
    pAboutAction = new QAction("About");




    mnuBar->addMenu(pmnuGame);
    mnuBar->addMenu(pmnuView);
    mnuBar->addMenu(pmnuSettings);
    mnuBar->addMenu(pmnuHelp);


    //Game Menu
    pmnuGame->addMenu(pmnuSubMenuNewGame);
    pmnuSubMenuNewGame->addAction(pSubMenuAllGamesAction);
    pmnuSubMenuNewGame->addAction(pSubMenuLogicAction);
    pmnuSubMenuNewGame->addAction(pSubMenuMathAction);
    pmnuSubMenuNewGame->addAction(pSubMenuMemoryAction);
    pmnuSubMenuNewGame->addAction(PSubMenuVerbalAction);
    pmnuSubMenuNewGame->addAction(pSubMenuCustomAction);

    pmnuGame->addAction(pPauseGameAction);
    pPauseGameAction->setDisabled(true);
    pmnuGame->addAction(pEndGameAction);
    pEndGameAction->setDisabled(true);
    pmnuGame->addSeparator();
    pmnuGame->addAction("Exit",this,SLOT(close()),Qt::Key_Escape);

    //View Menu
    pmnuView->addMenu(pmnuToolbar);

    pmnuToolbar->addAction(pShowAction);
    pShowAction->setCheckable(true);
    pShowAction->setChecked(true);

    pmnuToolbar->addMenu(pmnuSubMenuOrientation);
    pmnuSubMenuOrientation->addAction(pSubMenuHorizontal);
    pmnuSubMenuOrientation->addAction(pSubMenuVertical);

    pmnuView->addAction(pFullscreenAction);
    pFullscreenAction->setShortcut(Qt::Key_F11);
    pFullscreenAction->setCheckable(true);
    pFullscreenAction->setChecked(false);


    QObject::connect(pFullscreenAction,SIGNAL(triggered()),this,SLOT(fullScreenMode()));
    QObject::connect(pShowAction,SIGNAL(triggered()),SLOT(showToolbar()));
    QObject::connect(pSubMenuHorizontal,SIGNAL(triggered()),SLOT(toolBarHorizontalOrientation()));
    QObject::connect(pSubMenuVertical,SIGNAL(triggered()),SLOT(toolBarVerticalOrientation()));



    //Settings Menu
    pmnuSettings->addAction(pPreferencesACtion);

    //Help Menu
    pmnuHelp->addAction(pAboutAction);

    QObject::connect(pAboutAction,SIGNAL(triggered()),this,SLOT(slotAbout()));


    //setting menu bar
    setMenuBar(mnuBar);


    //setting background
    mainBackgroundPallete.setBrush(this->backgroundRole(),QBrush(QPixmap("C:/Users/sergo/Documents/QtProjects/3156605.jpg")));
    //this->setPalette(mainBackgroundPallete);



    toolBar = new QToolBar;



    QPixmap pixAll("C:/Users/sergo/Documents/QtProjects/QuizGame/data/app-graphics/allgames.png");

    pcmdAll = new QToolButton;
    pcmdAll->setToolButtonStyle(Qt::ToolButtonTextUnderIcon );
    pcmdAll->setIcon(pixAll);
    pcmdAll->setText("All");

    QPixmap pixLogic("C:/Users/sergo/Documents/QtProjects/QuizGame/data/app-graphics/logic-games.png");
    pcmdLogic = new QToolButton();
    pcmdLogic->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    pcmdLogic->setIcon(pixLogic);
    pcmdLogic->setText("Logic");


    QPixmap pixMath("C:/Users/sergo/Documents/QtProjects/QuizGame/data/app-graphics/math-games.png");
    pcmdMath = new QToolButton;
    pcmdMath->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    pcmdMath->setIcon(pixMath);
    pcmdMath->setText("Math");

    QPixmap pixMemory("C:/Users/sergo/Documents/QtProjects/QuizGame/data/app-graphics/memory-games.png");
    pcmdMemory = new QToolButton();
    pcmdMemory->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    pcmdMemory->setIcon(pixMemory);
    pcmdMemory->setText("Memory");

    QPixmap pixVerbal("C:/Users/sergo/Documents/QtProjects/QuizGame/data/app-graphics/verbal-games.png");
    pcmdVerbal = new QToolButton;
    pcmdVerbal->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    pcmdVerbal->setIcon(pixVerbal);
    pcmdVerbal->setText("Verbal");

    QPixmap pixPause("C:/Users/sergo/Documents/QtProjects/QuizGame/data/app-graphics/pause.png");
    pcmdPause = new QToolButton;
    pcmdPause->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    pcmdPause->setIcon(pixPause);
    pcmdPause->setText("Pause");
    pcmdPause->setDisabled(true);



    QPixmap pixEnd("C:/Users/sergo/Documents/QtProjects/QuizGame/data/app-graphics/endgame.png");
    pcmdEnd = new QToolButton;
    pcmdEnd->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    pcmdEnd->setIcon(pixEnd);
    pcmdEnd->setText("End");
    pcmdEnd->setDisabled(true);




    toolBar->addWidget(pcmdAll);
    toolBar->addWidget(pcmdLogic);
    toolBar->addWidget(pcmdMath);
    toolBar->addWidget(pcmdMemory);
    toolBar->addWidget(pcmdVerbal);
    toolBar->addWidget(pcmdPause);
    toolBar->addWidget(pcmdEnd);


    addToolBar(Qt::TopToolBarArea,toolBar);
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::TopToolBarArea);
    toolBar->setMovable(false);
    toolBar->setIconSize(QSize(40,40));
    toolBar->setStyleSheet("spacing: 20px ");






}




//  slots set up
void MainWindow::newGame()
{

}


void MainWindow::allGames()
{

}

void MainWindow::logicGame()
{

}

void MainWindow::mathGame()
{

}

void MainWindow::memoryGame()
{

}

void MainWindow::verbalGame()
{

}

void MainWindow::customGame()
{

}


void MainWindow::pause()
{

}

void MainWindow::end()
{

}

void MainWindow::fullScreenMode()
{
    if(pFullscreenAction->isChecked())
    {
        this->showMaximized();
    }
    else {
        this->showNormal();
    }
}


void MainWindow::showToolbar()
{
    if(pShowAction->isChecked())
    {
        toolBar->setVisible(true);
        pmnuSubMenuOrientation->setEnabled(true);
    }
    else
    {
        toolBar->setVisible(false);
        pmnuSubMenuOrientation->setDisabled(true);
    }
}

void MainWindow::toolBarHorizontalOrientation()
{
    removeToolBar(toolBar);
    addToolBar(Qt::TopToolBarArea,toolBar);
    toolBar->show();
}

void MainWindow::toolBarVerticalOrientation()
{
    removeToolBar(toolBar);
    addToolBar(Qt::LeftToolBarArea,toolBar);
    toolBar->show();

}
void MainWindow::preferences()
{

}

void MainWindow::slotAbout()
{
    //QWidget* pAbout = new QWidget;
    QLabel* aboutLbl = new QLabel("A brain teaser game for fun and to keep your brain trained ");
    aboutLbl->setMargin(10);
    aboutLbl->resize(400,200);
    aboutLbl->show();



}


MainWindow::~MainWindow()
{

}


