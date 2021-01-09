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
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFrame>
#include <QValidator>
#include <QList>
#include <QMessageBox>
#include <QSql>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QString>
//#include <QtAlgorithms>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

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
    QToolBar* mainToolBar;
    QToolBar* answToolbar;

    QToolButton* pcmdAll;
    QToolButton* pcmdLogic;
    QToolButton* pcmdMath;
    QToolButton* pcmdMemory;
    QToolButton* pcmdVerbal;
    QToolButton* pcmdPause;
    QToolButton* pcmdEnd;

    //central widget
    QWidget* centralWgt;


    //questions
    QLabel* questionLabel;
    QFile mathFile;
    QFile logicFile;
    QFile memoryFile;
    QFile verbalFile;
    QList<QByteArray> data;
    QFont font;
    int rowCount = 0;

    //Answers buttons
    QPushButton* answerBtn1;
    QPushButton* answerBtn2;
    QPushButton* answerBtn3;
    QPushButton* answerBtn4;
    QGridLayout* answersGridLayout;

    //anws toolbar buttons
    QPushButton* pcmdNext;
    QPushButton* pcmdOk;
    QPushButton* pcmdTip;
    QString userAnswInput;
    QLineEdit* answerInputLineEdit;

    //database
    QSqlDatabase db;
    QStringList strName;
    QSqlRecord rec;

    QStringList answersList;

    //Functions
    void connectingDB();
    void answToolbarSettings();
    void questionLabelSettings();
    void mathQuestions();
    void appendingAnswersInList();
    template <typename T>
    bool contains(QList<T> & stringList,const T & element);

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

    void OkToolBarButton();
    void TipToolbarButton();
    void NextToolBarButton();





};
#endif // MAINWINDOW_H
