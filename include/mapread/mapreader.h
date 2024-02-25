#ifndef MAPREADER_H
#define MAPREADER_H

#include <QString>
#include <QHash>
#include <QPoint>
#include <QObject>

class StateWrapper;
class AResponsabilityChainReader;

class MapReader : public QObject
{
    Q_OBJECT
public:
    MapReader( const QString & size = "7", const int difficulty = 0 );
    ~MapReader();
    void shuffleMap();
    void setSize( const QString & size );
    void setDifficulty( const int & difficulty );
    void setHashs();
    void emitHashSignal();

signals:
    void sendHashs(QHash<QPoint, StateWrapper*>& cells, QHash<QPoint, StateWrapper*>& walls);

private:
    AResponsabilityChainReader* _mapConverter;
    QString _mapSize;
    int _mapDifficulty;
    QString _map;
    QHash<QPoint, StateWrapper* > _blankHash;
    QHash<QPoint, StateWrapper* > _wallHash;
};

#endif // MAPREADER_H
