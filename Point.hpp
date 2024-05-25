#ifndef __Data_hpp
#define __Data_hpp
#include <cmath>

class Point final {
private:
    double lat, log, elev;
    unsigned long long int time;
public:
    Point(double _lat, double _log, double _elev, unsigned long long int _time)
        : lat(_lat), log(_log), elev(_elev), time(_time) {}

    // Широта
    double GetLatitude() const { return lat; }

    // Долгота
    double GetLongitude() const { return log; }

    // Высота над уровнем моря
    double GetElevation() const { return elev; }

    int GetTime() const { return time; }

    // Расстояние до другой точки
    double DistanceTo(const Point& other) const;

    int TimeTo(const Point& other) const;
};

#endif