#include "include/dialogtab.h"
#include <QLabel>
#include <QGridLayout>


DialogTab::DialogTab(QWidget *parent)
    : QTabWidget(parent)
{
    _tab1Widget = new QWidget(this);
    _tab1Layout = new QGridLayout(_tab1Widget);

    _firstRightClickLabel = new QLabel(tr("The right clic put a light on the game board"), _tab1Widget);
    _firstRightClickLabel->setWordWrap(true);
    _tab1Layout->addWidget(_firstRightClickLabel, 0, 0);


    _firstRightClickImageLabel = new QLabel( _tab1Widget );
    _firstRightClickImageLabel->setPixmap(QPixmap(":/images/commandsPictures/lightedPicture.png"));
    _firstRightClickImageLabel->setScaledContents(true);
    _tab1Layout->addWidget(_firstRightClickImageLabel, 0, 1);

    _secondRightClickLabel = new QLabel(tr("If you right clic on a light, you exchange the light by a cross"), _tab1Widget);
    _secondRightClickLabel->setWordWrap(true);
    _tab1Layout->addWidget(_secondRightClickLabel, 1, 0);

    _secondRightClickImageLabel = new QLabel(_tab1Widget);
    _secondRightClickImageLabel->setPixmap(QPixmap(":/images/commandsPictures/crossedPicture.png"));
    _secondRightClickImageLabel->setScaledContents(true);
    _tab1Layout->addWidget(_secondRightClickImageLabel, 1, 1);

    _thirdRightClickLabel = new QLabel(tr("If you right clic on a cross, you delete the cross"), _tab1Widget);
    _thirdRightClickLabel->setWordWrap(true);
    _tab1Layout->addWidget(_thirdRightClickLabel, 2, 0);

    _thirdRightClickImageLabel = new QLabel(this);
    _thirdRightClickImageLabel->setPixmap(QPixmap(":/images/commandsPictures/emptyPicture.png"));
    _thirdRightClickImageLabel->setScaledContents(true);
    _tab1Layout->addWidget(_thirdRightClickImageLabel, 2, 1);
    this->addTab(_tab1Widget, tr("Right Click"));




    _tab2Widget = new QWidget(this);
    _tab2Layout = new QGridLayout(_tab2Widget);
    _firstLeftClickLabel = new QLabel(tr("The left clic put a cross on the game board"), _tab2Widget);
    _firstLeftClickLabel->setWordWrap(true);
    _tab2Layout->addWidget(_firstLeftClickLabel, 0, 0);


    _firstLeftClickImageLabel = new QLabel( _tab2Widget );
    _firstLeftClickImageLabel->setPixmap(QPixmap(":/images/commandsPictures/crossedPicture.png"));
    _firstLeftClickImageLabel->setScaledContents(true);
    _tab2Layout->addWidget(_firstLeftClickImageLabel, 0, 1);

    _secondLeftClickLabel = new QLabel(tr("If you left clic on a cross, you exchange the cross by a light"), _tab2Widget);
    _secondLeftClickLabel->setWordWrap(true);
    _tab2Layout->addWidget(_secondLeftClickLabel, 1, 0);

    _secondLeftClickImageLabel = new QLabel(_tab2Widget);
    _secondLeftClickImageLabel->setPixmap(QPixmap(":/images/commandsPictures/lightedPicture.png"));
    _secondLeftClickImageLabel->setScaledContents(true);
    _tab2Layout->addWidget(_secondLeftClickImageLabel, 1, 1);

    _thirdLeftClickLabel = new QLabel(tr("If you right clic on a light, you delete the light"), _tab2Widget);
    _thirdLeftClickLabel->setWordWrap(true);
    _tab2Layout->addWidget(_thirdLeftClickLabel, 2, 0);

    _thirdLeftClickImageLabel = new QLabel(this);
    _thirdLeftClickImageLabel->setPixmap(QPixmap(":/images/commandsPictures/emptyPicture.png"));
    _thirdLeftClickImageLabel->setScaledContents(true);
    _tab2Layout->addWidget(_thirdLeftClickImageLabel, 2, 1);

    this->addTab(_tab2Widget, tr("Left Click"));




    _tab3Widget = new QWidget(this);
    _tab3Layout = new QGridLayout(_tab3Widget);

    _backtrackLabel = new QLabel(tr("if you press 'Ctrl + Z' you cancel your last action. Your number of backtrack is counted "), _tab3Widget);
    _backtrackLabel->setWordWrap(true);
    _tab3Layout->addWidget(_backtrackLabel, 0, 0);

    _backtrackImageLabel = new QLabel( _tab3Widget );
    _backtrackImageLabel->setPixmap(QPixmap(":/images/commandsPictures/crtZPicture.png"));
    _tab3Layout->addWidget(_backtrackImageLabel, 0, 1);

    this->addTab(_tab3Widget, tr("Backtrack"));


}

DialogTab::~DialogTab()
{

}
