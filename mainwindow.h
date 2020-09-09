#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QActionGroup>
#include <QObject>
#include <QWindow>
#include <QLabel>
#include <QToolBar>
#include <QToolButton>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QSplitter>
#include <QStatusBar>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QTextBrowser>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void que_one();

private:


    //Menu Bar
    QMenuBar* mnuBar;

    QMenu* pmnuGame;
    QMenu* pmnuView;
    QMenu* pmnuSettings;
    QMenu* pmnuHelp;

    //Game menu
    QMenu* pmnuSubMenuNewGame;
    QAction* pSubMenuAllGamesAction;
    QAction* pSubMenuLogicAction;
    QAction* pSubMenuMathAction;
    QAction* pSubMenuMemoryAction;
    QAction* PSubMenuVerbalAction;
    QAction* pSubMenuCustomAction;

    QAction* pPauseGameAction;
    QAction* pEndGameAction;


    //View menu
    QMenu* pmnuToolbar;
    QMenu* pmnuSubMenuOrientation;
    QAction* pSubMenuVertical;
    QAction* pSubMenuHorizontal;
    QAction* pShowAction;
    QAction* pFullscreenAction;

    //Settings Menu
    QAction* pPreferencesACtion;



    //Help Menu
    QAction* pAboutAction;



    //Palette
    QPalette mainBackgroundPallete;

    //Tool Bar
    QToolBar* toolBar;
    QToolBar* answerToolbar;

    QToolButton* pcmdAll;
    QToolButton* pcmdLogic;
    QToolButton* pcmdMath;
    QToolButton* pcmdMemory;
    QToolButton* pcmdVerbal;
    QToolButton* pcmdPause;
    QToolButton* pcmdEnd;


    //Central widget
    QWidget* centralWidget;
    
    //status bar
    QStatusBar* statusBar;


private slots:
    void newGame();
    void allGames();
    void logicGame();
    void mathGame();
    void memoryGame();
    void verbalGame();
    void customGame();

    void pause();
    void end();
    void fullScreenMode();


    void toolBarHorizontalOrientation();
    void toolBarVerticalOrientation();
    void showToolbar();


    void preferences();

    void slotAbout();


};
#endif // MAINWINDOW_H
