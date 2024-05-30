#ifndef __Memory_hpp
#define __Memory_hpp
#include "Point.hpp"
#include <list>
#include <map>
#include <vector>

class Memory final {
private:
	std::list<Point> points;
	std::vector<std::pair<double, double>> speedIntervals;
public:
	void AddSpdRange(const std::pair<double, double>& range);
	std::list<Point> GetPoints() const;
	void AddPoint(const Point& point);
	std::vector<std::pair<double, double>> GetSpeedIntervals() const;
};

#endif