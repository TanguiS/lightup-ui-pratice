#include <QApplication>
#include <QFileInfo>
#include <QTranslator>
#include <QLibraryInfo>
#include "include/mapread/mapreader.h"
#include "include/mainwindow.h"
#include <QDebug>
#include "include/gameBoard/gameboardmodel.h"
#include "include/gameBoard/gameboardpresenter.h"
#include "include/mapread/mapreader.h"
#include "include/commandActions/switchcommand.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SwitchCommand handlerCommand;
    GameBoardModel model(7);
    MapReader map;
    GameBoardPresenter presenter(model, map, handlerCommand);
    MainWindow w(&presenter);
    w.show();
    return a.exec();
}
