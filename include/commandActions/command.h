#ifndef COMMAND_H
#define COMMAND_H

class QPoint;
class GameBoardPresenter;

class Command
{
public:
    Command( GameBoardPresenter*);
    virtual ~Command();
    virtual void execute()=0;
protected:
    GameBoardPresenter* getPresenter()const;

private:
    GameBoardPresenter *_presenter;
};

#endif // COMMAND_H
