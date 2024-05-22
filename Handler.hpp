#ifndef __Handler_hpp
#define __Handler_hpp
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <fstream>
#include <iostream>
#include "Point.hpp"
#include <unordered_map>

class Handler final {
private:
	std::list<Point> points;
	int summTime;//s
	double distanñe;//m
	double averSpeed;//m/s
	int moutTime;//s
	int stopTime;//s
	double averMoutSpeed;//m/s
	double maxSpeed;//m/s
	double minAltit;//m
	double maxAltit;//m
	double summAscend;//m
	double summDescend;//m
	std::list<std::pair<std::pair<double, double>, unsigned long long int>> speedIntervals;
public:
	std::list<Point>& GetPoints();
	int GetSummTime();
	double GetDistanñe();//m
	double GetAverSpeed();//m/s
	int GetMoutTime();//s
	int GetStopTime();//s
	double GetAverMoutSpeed();//m/s
	double GetMaxSpeed();//m/s
	double GetMinAltit();//m
	double GetMaxAltit();//m
	double GetSummAscend();//m
	double GetSummDescend();//m
	void CalcValues(std::list<std::pair<std::pair<double, double>, unsigned long long int>> speedIntervals);
	void PrintValues();
	std::list<std::pair<std::pair<double, double>, unsigned long long int>> GetSpeedIntervals();
};

#endif