#include "include/mapread/mapreader.h"
#include "include/mapread/blankresponsabilitychainreader.h"
#include "include/mapread/wallnumberresponsabilitychainreader.h"
#include "include/mapread/wallresponsabilitychainreader.h"
#include "include/cell/state/statewrapper.h"
#include "include/cell/state/blankstate.h"
#include "include/cell/state/wallstate.h"
#include "include/cell/state/wallnumberstate.h"

#include <QFile>
#include <QDebug>
#include <QRandomGenerator>
#include <include/gameBoard/hashqpoint.h>

MapReader::MapReader( const QString & size, const int difficulty )
    : _mapSize( size ),
      _mapDifficulty( difficulty )
{
    _mapConverter = new BlankResponsabilityChainReader( new WallResponsabilityChainReader( new WallNumberResponsabilityChainReader() ) );
    _blankHash = QHash<QPoint, StateWrapper* >();
    _wallHash = QHash<QPoint, StateWrapper* >();
}

MapReader::~MapReader()
{
    delete _mapConverter;
}

void MapReader::shuffleMap()
{
    QString Difficulty;
    if (_mapDifficulty == 0 ) {
        Difficulty = "easy";
    } else if ( _mapDifficulty == 1 ) {
        Difficulty = "normal";
    } else {
        Difficulty = "hard";
    }
    QFile file( ":maps/maps/"+_mapSize+"_"+Difficulty+".txt" );
    if ( !file.open(QIODevice::ReadOnly | QIODevice::Text) ) {
        return;
    }
    int numberOfMap = file.readLine().toInt();
    int mapNumberChoosen = QRandomGenerator::global()->bounded(numberOfMap) + 1;
    QString maps;
    for ( int i = 0; i < mapNumberChoosen; i++ ) {
        maps = file.readLine();
    }
    _map = maps.left( maps.size()-1 );
    file.close();
    setHashs();
    emit sendHashs( _blankHash, _wallHash );

}

void MapReader::setSize(const QString &size)
{
    _mapSize = size;
    this->shuffleMap();
}

void MapReader::setDifficulty(const int &difficulty)
{
    _mapDifficulty = difficulty;
    this->shuffleMap();
}

void MapReader::setHashs()
{
    QPair<StateWrapper *, backgroundType> blocInterpretation;
    int i = 0;
    int size = _mapSize.toInt();
    int column;
    int row;
    _blankHash.clear();
    _wallHash.clear();
    for ( auto bloc = _map.begin(); bloc != _map.end(); bloc++ ) {
        blocInterpretation = _mapConverter->convertMapToWrapper( * bloc );
        column = ( i % size );
        row = (i / size );
        if ( blocInterpretation.second == blank ) {
           _blankHash.insert( QPoint( row, column ), blocInterpretation.first );
        } else {
            _wallHash.insert( QPoint( row, column ), blocInterpretation.first );
        }
        i++;
    }
}

void MapReader::emitHashSignal()
{
    setHashs();
    emit sendHashs( _blankHash, _wallHash );
}
