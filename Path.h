#ifndef PATH_H
#define PATH_H

#include <vector>
#include <QVector2D>

class Path {
public:
    static std::vector<QVector2D> getWaypoints() {
        // Replace these points with the actual waypoints for your path
        return {
            QVector2D(225, 0),
            QVector2D(225, 257),
            QVector2D(277, 319),
            QVector2D(596, 319),
            QVector2D(640, 262),
            QVector2D(640, 177),
            QVector2D(690, 127),
            QVector2D(937, 127),
            QVector2D(994, 209),
            QVector2D(994, 386),
            QVector2D(944, 415),
            QVector2D(184, 420),
            QVector2D(132, 453),
            QVector2D(132, 527),
            QVector2D(175, 577),
            QVector2D(1160, 577),
            QVector2D(1217, 527),
            QVector2D(1217,-25)
        };
    }
};

#endif // PATH_H
