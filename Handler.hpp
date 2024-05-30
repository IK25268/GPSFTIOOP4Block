#ifndef __Handler_hpp
#define __Handler_hpp

#include "Memory.hpp"
#include <map>
#include <iostream>
#include <string>

class Handler final {
private:
	int summTime;//s
	double distan�e;//m
	double averSpeed;//m/s
	int moutTime;//s
	int stopTime;//s
	double averMoutSpeed;//m/s
	double maxSpeed;//m/s
	double minAltit;//m
	double maxAltit;//m
	double summAscend;//m
	double summDescend;//m
	void CalcDiff(unsigned long long int& diffTime, double& diffDist, double& diffElev, double& instSpd, const Point& prevPoint, const Point& currPoint);
public:
	Handler();
	int GetSummTime() const;//s
	double GetDistan�e() const;//m
	double GetAverSpeed() const;//m/s
	int GetMoutTime() const;//s
	int GetStopTime() const;//s
	double GetAverMoutSpeed() const;//m/s
	double GetMaxSpeed() const;//m/s
	double GetMinAltit() const;//m
	double GetMaxAltit() const;//m
	double GetSummAscend() const;//m
	double GetSummDescend() const;//m
	void CalcValues(const Memory& memory, double spdThrshld = 0.3);
};

#endif