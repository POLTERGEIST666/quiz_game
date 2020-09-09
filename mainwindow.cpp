#include "mainwindow.h"
#include <QActionGroup>
#include <QObject>






MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)


{

    resize(800,650);
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



    //adding menus in menubar
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

    QObject::connect(pSubMenuAllGamesAction,SIGNAL(triggered()),SLOT(allGames()));
    QObject::connect(pSubMenuLogicAction,SIGNAL(triggered()),SLOT(logicGame()));
    QObject::connect(pSubMenuMathAction,SIGNAL(triggered()),SLOT(mathGame()));
    QObject::connect(pSubMenuMemoryAction,SIGNAL(triggered()),SLOT(memoryGame()));
    QObject::connect(PSubMenuVerbalAction,SIGNAL(triggered()),SLOT(verbalGame()));
    QObject::connect(pSubMenuCustomAction,SIGNAL(triggered()),SLOT(customGame()));


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



    mainToolBar = new QToolBar;



    QPixmap pixAll("C:/Users/sergo/Documents/QtProjects/QuizGame/data/app-graphics/allgames.png");

    pcmdAll = new QToolButton;
    pcmdAll->setToolButtonStyle(Qt::ToolButtonTextUnderIcon );
    pcmdAll->setIcon(pixAll);
    pcmdAll->setText("All");
    pcmdAll->setCheckable(true);

    QObject::connect(pcmdAll,SIGNAL(clicked()),SLOT(allGames()));


    QPixmap pixLogic("C:/Users/sergo/Documents/QtProjects/QuizGame/data/app-graphics/logic-games.png");
    pcmdLogic = new QToolButton();
    pcmdLogic->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    pcmdLogic->setIcon(pixLogic);
    pcmdLogic->setText("Logic");
    pcmdLogic->setCheckable(true);

    QObject::connect(pcmdLogic,SIGNAL(clicked()),SLOT(logicGame()));

    QPixmap pixMath("C:/Users/sergo/Documents/QtProjects/QuizGame/data/app-graphics/math-games.png");
    pcmdMath = new QToolButton;
    pcmdMath->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    pcmdMath->setIcon(pixMath);
    pcmdMath->setText("Math");
    pcmdMath->setCheckable(true);

    QObject::connect(pcmdMath,SIGNAL(clicked()),SLOT(mathGame()));


    QPixmap pixMemory("C:/Users/sergo/Documents/QtProjects/QuizGame/data/app-graphics/memory-games.png");
    pcmdMemory = new QToolButton();
    pcmdMemory->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    pcmdMemory->setIcon(pixMemory);
    pcmdMemory->setText("Memory");
    pcmdMemory->setCheckable(true);

    QObject::connect(pcmdMemory,SIGNAL(clicked()),SLOT(memoryGame()));

    QPixmap pixVerbal("C:/Users/sergo/Documents/QtProjects/QuizGame/data/app-graphics/verbal-games.png");
    pcmdVerbal = new QToolButton;
    pcmdVerbal->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    pcmdVerbal->setIcon(pixVerbal);
    pcmdVerbal->setText("Verbal");
    pcmdVerbal->setCheckable(true);

    QObject::connect(pcmdVerbal,SIGNAL(clicked()),SLOT(verbalGame()));

    QPixmap pixPause("C:/Users/sergo/Documents/QtProjects/QuizGame/data/app-graphics/pause.png");
    pcmdPause = new QToolButton;
    pcmdPause->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    pcmdPause->setIcon(pixPause);
    pcmdPause->setText("Pause");
    pcmdPause->setDisabled(true);
    pcmdPause->setCheckable(true);

    QObject::connect(pcmdPause,SIGNAL(clicked()),SLOT(pause()));

    QPixmap pixEnd("C:/Users/sergo/Documents/QtProjects/QuizGame/data/app-graphics/endgame.png");
    pcmdEnd = new QToolButton;
    pcmdEnd->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    pcmdEnd->setIcon(pixEnd);
    pcmdEnd->setText("End");
    pcmdEnd->setDisabled(true);
    pcmdEnd->setCheckable(true);

    QObject::connect(pcmdEnd,SIGNAL(clicked()),SLOT(end()));


    //adding toolbar widgets
    mainToolBar->addWidget(pcmdAll);
    mainToolBar->addWidget(pcmdLogic);
    mainToolBar->addWidget(pcmdMath);
    mainToolBar->addWidget(pcmdMemory);
    mainToolBar->addWidget(pcmdVerbal);
    mainToolBar->addWidget(pcmdPause);
    mainToolBar->addWidget(pcmdEnd);


    addToolBar(Qt::TopToolBarArea,mainToolBar);
    mainToolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::TopToolBarArea);
    mainToolBar->setMovable(false);
    mainToolBar->setIconSize(QSize(40,40));
    mainToolBar->setStyleSheet("spacing: 20px ");


    centralWgt = new QWidget;

    this->setCentralWidget(centralWgt);


    

}


void MainWindow::answToolbarSetting()
{
    QToolBar* answToolbar = new QToolBar;

    QPushButton* pcmdNext = new QPushButton("Next",answToolbar);
    QPushButton* pcmdOk = new QPushButton("OK",answToolbar);
    QPushButton* pcmdTip = new QPushButton("Tip",answToolbar);

    QLineEdit* answerInput = new QLineEdit (answToolbar);

    answToolbar->addWidget(answerInput);
    answToolbar->addWidget(pcmdOk);
    answToolbar->addWidget(pcmdTip);
    answToolbar->addWidget(pcmdNext);

    pcmdOk->setFlat(true);
    pcmdOk->setIconSize(QSize(40,40));

    pcmdOk->setIcon(QPixmap(":/data/app-graphics/ok.png"));
    pcmdTip->setIcon(QPixmap(":/data/app-graphics/tip.png"));
    pcmdNext->setIcon(QPixmap(":/data/app-graphics/next.png"));

    QObject::connect(pcmdOk,SIGNAL(clicked()),SLOT()); //remember to add slot
    QObject::connect(pcmdTip,SIGNAL(clicked()),SLOT());//remember to add slot
    QObject::connect(pcmdNext,SIGNAL(clicked()),SLOT());//remember to add slot


    answToolbar->setMovable(false);
    this->addToolBar(Qt::BottomToolBarArea,answToolbar);
}

void MainWindow::buttonsSetting()
{
    if(pcmdAll->isChecked())
    {
        pSubMenuAllGamesAction->setDisabled(true);
        pSubMenuLogicAction->setDisabled(true);
        pSubMenuMathAction->setDisabled(true);
        pSubMenuMemoryAction->setDisabled(true);
        PSubMenuVerbalAction->setDisabled(true);
        pSubMenuCustomAction->setDisabled(true);
        pcmdAll->setDisabled(true);
        pcmdLogic->setDisabled(true);
        pcmdMath->setDisabled(true);
        pcmdMemory->setDisabled(true);
        pcmdVerbal->setDisabled(true);
    }
    if(pcmdLogic->isChecked())
    {
        pSubMenuAllGamesAction->setDisabled(true);
        pSubMenuLogicAction->setDisabled(true);
        pSubMenuMathAction->setDisabled(true);
        pSubMenuMemoryAction->setDisabled(true);
        PSubMenuVerbalAction->setDisabled(true);
        pSubMenuCustomAction->setDisabled(true);
        pcmdAll->setDisabled(true);
        pcmdLogic->setDisabled(true);
        pcmdMath->setDisabled(true);
        pcmdMemory->setDisabled(true);
        pcmdVerbal->setDisabled(true);
    }
    if(pcmdMath->isChecked())
    {
        pSubMenuAllGamesAction->setDisabled(true);
        pSubMenuLogicAction->setDisabled(true);
        pSubMenuMathAction->setDisabled(true);
        pSubMenuMemoryAction->setDisabled(true);
        PSubMenuVerbalAction->setDisabled(true);
        pSubMenuCustomAction->setDisabled(true);
        pcmdAll->setDisabled(true);
        pcmdLogic->setDisabled(true);
        pcmdMath->setDisabled(true);
        pcmdMemory->setDisabled(true);
        pcmdVerbal->setDisabled(true);
    }
    if(pcmdMemory->isChecked())
    {
        pSubMenuAllGamesAction->setDisabled(true);
        pSubMenuLogicAction->setDisabled(true);
        pSubMenuMathAction->setDisabled(true);
        pSubMenuMemoryAction->setDisabled(true);
        PSubMenuVerbalAction->setDisabled(true);
        pSubMenuCustomAction->setDisabled(true);
        pcmdAll->setDisabled(true);
        pcmdLogic->setDisabled(true);
        pcmdMath->setDisabled(true);
        pcmdMemory->setDisabled(true);
        pcmdVerbal->setDisabled(true);
    }
    if(pcmdVerbal->isChecked())
    {
        pSubMenuAllGamesAction->setDisabled(true);
        pSubMenuLogicAction->setDisabled(true);
        pSubMenuMathAction->setDisabled(true);
        pSubMenuMemoryAction->setDisabled(true);
        PSubMenuVerbalAction->setDisabled(true);
        pSubMenuCustomAction->setDisabled(true);
        pcmdAll->setDisabled(true);
        pcmdLogic->setDisabled(true);
        pcmdMath->setDisabled(true);
        pcmdMemory->setDisabled(true);
        pcmdVerbal->setDisabled(true);
    }

    pcmdPause->setEnabled(true);
    pcmdEnd->setEnabled(true);

    pPauseGameAction->setEnabled(true);
    pEndGameAction->setEnabled(true);

}

//  slots set up
void MainWindow::newGame()
{


}


void MainWindow::allGames()
{


    buttonsSetting();
    answToolbarSetting();
}

void MainWindow::logicGame()
{
    buttonsSetting();
    answToolbarSetting();
}

void MainWindow::mathGame()
{
    buttonsSetting();
    answToolbarSetting();
}

void MainWindow::memoryGame()
{
    buttonsSetting();
    answToolbarSetting();
}

void MainWindow::verbalGame()
{
    buttonsSetting();
    answToolbarSetting();
}

void MainWindow::customGame()
{
    buttonsSetting();
    answToolbarSetting();
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
        mainToolBar->setVisible(true);
        pmnuSubMenuOrientation->setEnabled(true);
    }
    else
    {
        mainToolBar->setVisible(false);
        pmnuSubMenuOrientation->setDisabled(true);
    }
}

void MainWindow::toolBarHorizontalOrientation()
{
    removeToolBar(mainToolBar);
    addToolBar(Qt::TopToolBarArea,mainToolBar);
    mainToolBar->show();
}

void MainWindow::toolBarVerticalOrientation()
{
    removeToolBar(mainToolBar);
    addToolBar(Qt::LeftToolBarArea,mainToolBar);
    mainToolBar->show();

}
void MainWindow::preferences()
{

}

void MainWindow::slotAbout()
{
    //QWidget* pAbout = new QWidget;
    QLabel* aboutLbl = new QLabel("A brain teaser game for fun and to keep your brain trained");
    aboutLbl->setMargin(10);
    aboutLbl->resize(400,200);
    aboutLbl->show();



}


MainWindow::~MainWindow()
{

}


