#include "Memory.hpp"

void Memory::AddSpdRange(const std::pair<double, double>& range)
{
	speedIntervals.insert({speedIntervals.size(), range});
}

std::list<Point> Memory::GetPoints() const
{
	return points;
}

void Memory::AddPoint(const Point& point)
{
	points.push_back(point);
}

std::map<unsigned int, std::pair<double, double>> Memory::GetSpeedIntervals() const
{
	return speedIntervals;
}
