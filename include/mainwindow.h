#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QElapsedTimer>
#include <QResizeEvent>

class QTimer;
class QElapsedTimer;
class GameBoardScene;
class GameBoardPresenter;
class MapReader;
class QTabWidget;
class QTranslator;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(GameBoardPresenter* presenter, QWidget *parent = nullptr);
    ~MainWindow();
    void changeLanguage( const QString& language );

public slots:
    void updateStopWach();
    void startGame();
    void loadView();
    void changeSize(const QString );
    void changeDifficulty(const int );
    void changeNumberBackTracks( const QString );
    void launchVictoryMessage();
    void launchNotVictoryMessage();
    void launchCopyRight();
    void launchRules();
    void setFirstTable();
    void launchCommandInstruction();
    void frenchLanguage();
    void englishLanguage();

signals:
    void launchLoad();

private:


private:
    Ui::MainWindow *ui;
    QTimer *_stopWatch;
    GameBoardScene* _mainScene;
    GameBoardPresenter* _presenter;
    QElapsedTimer _elapse;
    QTranslator* _translator;
    QString _language = "en";
};

#endif // MAINWINDOW_H
