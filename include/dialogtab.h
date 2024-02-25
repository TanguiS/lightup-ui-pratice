#ifndef DIALOGTAB_H
#define DIALOGTAB_H

#include <QTabWidget>

class QLabel;
class QGridLayout;

class DialogTab : public QTabWidget
{
    Q_OBJECT

public:
    DialogTab( QWidget *parent = nullptr);
    ~DialogTab();


private:
    QGridLayout* _tab1Layout;
    QWidget* _tab1Widget;

    QLabel* _firstRightClickLabel;
    QLabel* _firstRightClickImageLabel;

    QLabel* _secondRightClickLabel;
    QLabel* _secondRightClickImageLabel;

    QLabel* _thirdRightClickLabel;
    QLabel* _thirdRightClickImageLabel;


    QWidget* _tab2Widget;
    QGridLayout* _tab2Layout;

    QLabel* _firstLeftClickLabel;
    QLabel* _firstLeftClickImageLabel;

    QLabel* _secondLeftClickLabel;
    QLabel* _secondLeftClickImageLabel;

    QLabel* _thirdLeftClickLabel;
    QLabel* _thirdLeftClickImageLabel;


    QWidget* _tab3Widget;
    QGridLayout* _tab3Layout;

    QLabel* _backtrackLabel;
    QLabel* _backtrackImageLabel;
};

#endif // DIALOGTAB_H
