#ifndef GAMEBOARDVIEW_H
#define GAMEBOARDVIEW_H

#include <QGraphicsView>

class GameBoardScene;

class GameBoardView : public QGraphicsView {
public:
    GameBoardView(QWidget *parent = nullptr);

    // QWidget interface
protected:
    void resizeEvent( QResizeEvent* ) override;
};

#endif // GAMEBOARDVIEW_H
