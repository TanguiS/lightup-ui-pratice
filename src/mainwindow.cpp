#include "include/mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QTime>
#include <QLabel>
#include <QResizeEvent>
#include <QComboBox>
#include <QShortcut>
#include <QMessageBox>
#include <QFileInfo>
#include <QDialog>
#include <QAction>
#include <QTranslator>
#include <QIcon>
#include "include/gameBoard/gameboardscene.h"
#include "include/gameBoard/gameboardmodel.h"
#include "include/gameBoard/gameboardpresenter.h"
#include "include/mapread/mapreader.h"
#include "include/dialogtab.h"
#include <QDebug>
#include <QtMath>
#include <QImage>

MainWindow::MainWindow(GameBoardPresenter* presenter, QWidget *parent   ) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), _mainScene(nullptr), _presenter(presenter)
{
    ui->setupUi(this);
    this->setWindowTitle( tr("Akari"));
    _stopWatch = new QTimer(this);
    connect( _stopWatch, &QTimer::timeout, this, &MainWindow::updateStopWach );
    connect( ui->_startButton, &QPushButton::clicked, this, &MainWindow::startGame );
    connect(_presenter, &GameBoardPresenter::loaded, this, &MainWindow::loadView);
    connect(_presenter, &GameBoardPresenter::lightedPercentage, ui->_lightedPercentage, &QLabel::setText);
    connect(_presenter, &GameBoardPresenter::validatedWallPercentage, ui->_validatedWallPercentage, &QLabel::setText);
    connect(ui->_tabWidget, &QTabWidget::currentChanged, [this](int) {
       ui->_gameGraphicsView->resize(ui->_gameGraphicsView->size().width() - 1, ui->_gameGraphicsView->size().height() - 1);
    });
    ui->_tabWidget->setTabEnabled( 1, false );
    connect( ui->_sizeComboBox, SIGNAL(currentTextChanged(const QString&)), this, SLOT(changeSize(const QString&) ) );
    connect( ui->_difficultyComboBox, SIGNAL(currentIndexChanged(const int)), _presenter, SLOT(changeDifficulty(const int) ) );
    connect( ui->_shuffleButton, &QPushButton::clicked, _presenter, &GameBoardPresenter::loadNewMap );
    connect( ui->_resetButton, &QPushButton::clicked, _presenter , &GameBoardPresenter::emitResetSignal );
    connect( ui->_submitButton, &QPushButton::clicked, _presenter, &GameBoardPresenter::communication );
    connect( ui->_actionRules, &QAction::triggered, this, &MainWindow::launchRules );
    connect( ui->_actionCopyRight, &QAction::triggered, this, &MainWindow::launchCopyRight );
    connect( ui->_actionCommands, &QAction::triggered, this, &MainWindow::launchCommandInstruction );
    connect(_presenter, &GameBoardPresenter::wonGame, this, &MainWindow::launchVictoryMessage);
    connect(_presenter, &GameBoardPresenter::notWonGame, this, &MainWindow::launchNotVictoryMessage);
    QShortcut *undoShortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this);
    connect(undoShortcut, &QShortcut::activated, _presenter, &GameBoardPresenter::handleUndo );
    connect( _presenter, &GameBoardPresenter::numberBackTracks, this, &MainWindow::changeNumberBackTracks );
    connect( _presenter, &GameBoardPresenter::sendLockingPage, this, &MainWindow::setFirstTable );
    _presenter->loadNewMap();
    ui->_stopWatchWidget->setSegmentStyle(QLCDNumber::Flat);

    _translator = new QTranslator( this );

    QAction* _actionFrench = new QAction(tr("French"), this);
    _actionFrench->setIcon( QIcon( ":/images/icons/french_flag.png" ) );
    QAction* _actionEnglish = new QAction(tr("English"), this);
    _actionEnglish->setIcon( QIcon( ":/images/icons/union_jack_flag.png" ) );

    QMenu* menu = new QMenu(this);
    menu->addAction(_actionFrench);
    menu->addAction(_actionEnglish);

    connect(ui->_actionLanguages, &QAction::hovered, [menu]() {
        menu->exec(QCursor::pos());
    });

    connect( _actionFrench, &QAction::triggered, this, &MainWindow::frenchLanguage );
    connect( _actionEnglish, &QAction::triggered, this, &MainWindow::englishLanguage );

}

MainWindow::~MainWindow()
{
    delete ui;
    delete _mainScene;
}

void MainWindow::updateStopWach()
{
    qint64 elapsed = _elapse.elapsed();
    QTime time = QTime::fromMSecsSinceStartOfDay(elapsed);
    QString timeString = time.toString("hh:mm:ss");
    ui->_stopWatchWidget->display( timeString );
}

void MainWindow::startGame()
{
    _elapse.start();
    _stopWatch->start(1000);
    ui->_gameGraphicsView->setEnabled(true);
    ui->_tabWidget->setTabEnabled( 1, true );
    ui->_tabWidget->setCurrentIndex( 1 );
    ui->_submitButton->setEnabled(true);
    ui->_resetButton->setEnabled(true);
}

void MainWindow::loadView()
{
    delete _mainScene;
    _mainScene = new GameBoardScene(*_presenter, ui->_gameGraphicsView->size(),ui->_gameGraphicsView);
    _mainScene->setBackgroundBrush(QBrush(Qt::lightGray));
    ui->_gameGraphicsView->setScene(_mainScene);
    ui->_preview->setScene(_mainScene);
}

void MainWindow::changeSize( const QString size )
{
    _presenter->changeSize( size );
    setFirstTable();
}

void MainWindow::changeDifficulty(const int difficulty )
{
    _presenter->changeDifficulty( difficulty );
    setFirstTable();
}

void MainWindow::changeNumberBackTracks(const QString value)
{
    ui->_countBacktracks->setText( value );
}

void MainWindow::launchVictoryMessage()
{
    _stopWatch->stop();
    ui->_gameGraphicsView->setEnabled( false );
    QMessageBox victoryMessage;
    QString text = tr("Congratulations you won in %1 and used %2 backtrack(s)");
    qint64 elapsed = _elapse.elapsed();
    QTime time = QTime::fromMSecsSinceStartOfDay(elapsed);
    QString timeString = time.toString("hh:mm:ss");
    victoryMessage.about(nullptr, tr("Victory"), text.arg(timeString).arg(ui->_countBacktracks->text()));
    _elapse.invalidate();
    ui->_submitButton->setEnabled(false);
    ui->_resetButton->setEnabled(false);
}

void MainWindow::launchNotVictoryMessage()
{
    QMessageBox notVictoryMessage;
    QString text = tr("Unfortunatly, you didn't solve the game.");
    notVictoryMessage.about(nullptr, tr("Sorry"), text);
}

void MainWindow::launchCopyRight()
{
    QMessageBox licence;
    licence.about(nullptr, tr("About us"),tr("AKARI\n(c) Developped by Kylian Picque and Tangui Steimetz"));
}

void MainWindow::launchRules()
{
    QMessageBox rules;
    QFile file;
    QString qmFile = QString(":/others/Rules_%1.txt").arg(_language);
    if ( QFileInfo(qmFile).exists() ) {
        file.setFileName( qmFile );
    } else {
        file.setFileName(":/others/Rules.txt" );
    }
    QString content;
    if ( !file.open(QIODevice::ReadOnly | QIODevice::Text) ) {
       return;
    }
    QTextStream in(&file);
    content = in.readAll();
    rules.about(nullptr, tr("Rules"),content);
}

void MainWindow::setFirstTable()
{
    ui->_tabWidget->setCurrentIndex( 0 );
    ui->_tabWidget->setTabEnabled( 1, false );
}

void MainWindow::launchCommandInstruction()
{
    QDialog dialog(this);
    dialog.setFixedSize(600, 700);
    QTabWidget tabWidget(&dialog);
    DialogTab tab(&dialog);
    QVBoxLayout layout(&dialog);
    layout.addWidget(&tab);
    dialog.setLayout(&layout);
    dialog.exec();
}

void MainWindow::frenchLanguage()
{
    _language = "fr";
    changeLanguage("fr");
}

void MainWindow::englishLanguage()
{
    _language = "en";
    changeLanguage("en");
}

void MainWindow::changeLanguage(const QString &language)
{
    QString qmFile = QString(":/translation/LightUp_%1.qm").arg(language);
    if ( _translator->load(qmFile) ) {
       qApp->installTranslator(_translator);
       ui->retranslateUi(this);
       return;
    }
    qApp->removeTranslator( _translator );
    ui->retranslateUi(this);
}
