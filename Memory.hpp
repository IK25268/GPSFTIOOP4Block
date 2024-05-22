#ifndef __Memory_hpp
#define __Memory_hpp
#include "Point.hpp"
#include <list>
#include <map>

class Memory final {
private:
	std::list<Point> points;
	std::map<unsigned int, std::pair<double, double>> speedIntervals;
public:
	void AddSpdRange(std::pair<double, double> range);
	std::list<Point> ReturnPoints();
	void AddPoint(double _lat, double _log, double _elev, unsigned long long int _time);
	std::map<unsigned int, std::pair<double, double>> ReturnSpeedIntervals();
};

#endif