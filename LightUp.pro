QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/cell/cellview.cpp \
    src/cell/decorator/blankcell.cpp \
    src/cell/decorator/bulbcell.cpp \
    src/cell/decorator/cell.cpp \
    src/cell/decorator/celldecorator.cpp \
    src/cell/decorator/crosscell.cpp \
    src/cell/decorator/invalidbulbcell.cpp \
    src/cell/decorator/lightcell.cpp \
    src/cell/decorator/numbercell.cpp \
    src/cell/decorator/wallcell.cpp \
    src/cell/state/blankcrossstate.cpp \
    src/cell/state/blankstate.cpp \
    src/cell/state/bulbstate.cpp \
    src/cell/state/invalidbulbstate.cpp \
    src/cell/state/lightcrossstate.cpp \
    src/cell/state/lightstate.cpp \
    src/cell/state/statecell.cpp \
    src/cell/state/statewrapper.cpp \
    src/cell/state/wallnumberstate.cpp \
    src/cell/state/wallstate.cpp \
    src/cell/state/wallvalidnumberstate.cpp \
    src/commandActions/command.cpp \
    src/commandActions/leftclickcommand.cpp \
    src/commandActions/rightclickcommand.cpp \
    src/commandActions/switchcommand.cpp \
    src/commandActions/undocommand.cpp \
    src/dialogtab.cpp \
    src/gameBoard/gameboardcellmanager.cpp \
    src/gameBoard/gameboardmodel.cpp \
    src/gameBoard/gameboardpresenter.cpp \
    src/gameBoard/gameboardscene.cpp \
    src/gameBoard/gameboardview.cpp \
    src/gameBoard/gameboardwallmanager.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/mapread/AResponsabilityChainReader.cpp \
    src/mapread/blankresponsabilitychainreader.cpp \
    src/mapread/mapreader.cpp \
    src/mapread/wallnumberresponsabilitychainreader.cpp \
    src/mapread/wallresponsabilitychainreader.cpp \
    src/tabwidgetbackground.cpp




HEADERS += \
    include/cell/cellcomponent.h \
    include/cell/cellview.h \
    include/cell/decorator/blankcell.h \
    include/cell/decorator/bulbcell.h \
    include/cell/decorator/cell.h \
    include/cell/decorator/celldecorator.h \
    include/cell/decorator/crosscell.h \
    include/cell/decorator/invalidbulbcell.h \
    include/cell/decorator/lightcell.h \
    include/cell/decorator/numbercell.h \
    include/cell/decorator/wallcell.h \
    include/cell/state/blankcrossstate.h \
    include/cell/state/blankstate.h \
    include/cell/state/bulbstate.h \
    include/cell/state/invalidbulbstate.h \
    include/cell/state/lightcrossstate.h \
    include/cell/state/lightstate.h \
    include/cell/state/statecell.h \
    include/cell/state/statewrapper.h \
    include/cell/state/wallnumberstate.h \
    include/cell/state/wallstate.h \
    include/cell/state/wallvalidnumberstate.h \
    include/commandActions/command.h \
    include/commandActions/leftclickcommand.h \
    include/commandActions/rightclickcommand.h \
    include/commandActions/switchcommand.h \
    include/commandActions/undocommand.h \
    include/dialogtab.h \
    include/gameBoard/gameboardcellmanager.h \
    include/gameBoard/gameboardmodel.h \
    include/gameBoard/gameboardpresenter.h \
    include/gameBoard/gameboardscene.h \
    include/gameBoard/gameboardview.h \
    include/gameBoard/gameboardwallmanager.h \
    include/gameBoard/hashqpoint.h \
    include/mainwindow.h \
    include/mapread/AResponsabilityChainReader.h \
    include/mapread/blankresponsabilitychainreader.h \
    include/mapread/mapreader.h \
    include/mapread/wallnumberresponsabilitychainreader.h \
    include/mapread/wallresponsabilitychainreader.h \
    include/tabwidgetbackground.h \
    src/tabwidgetbackground.h


FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    LightUp_fr.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
