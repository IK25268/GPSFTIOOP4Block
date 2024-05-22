#include "Memory.hpp"

void Memory::AddSpdRange(std::pair<double, double> range)
{
	speedIntervals.insert({speedIntervals.size(), range});
}

std::list<Point> Memory::ReturnPoints()
{
	return points;
}

void Memory::AddPoint(double _lat, double _log, double _elev, unsigned long long int _time)
{
	points.push_back({_lat, _log, _elev, _time});
}

std::map<unsigned int, std::pair<double, double>> Memory::ReturnSpeedIntervals()
{
	return speedIntervals;
}
