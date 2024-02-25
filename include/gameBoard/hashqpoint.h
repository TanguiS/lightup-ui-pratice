#ifndef HASHQPOINT_H
#define HASHQPOINT_H

#include <QHash>
#include <QPoint>
#include <QPair>

inline uint qHash (const QPoint & key)
{
    return qHash (QPair<int,int>(key.x(), key.y()) );
}

#endif // HASHQPOINT_H
