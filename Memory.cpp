#include "Memory.hpp"

void Memory::AddSpdRange(const std::pair<double, double>& range)
{
	speedIntervals.push_back(range);
}

std::list<Point> Memory::GetPoints() const
{
	return points;
}

void Memory::AddPoint(const Point& point)
{
	points.push_back(point);
}

std::vector<std::pair<double, double>> Memory::GetSpeedIntervals() const
{
	return speedIntervals;
}
