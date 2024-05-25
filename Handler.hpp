#ifndef __Handler_hpp
#define __Handler_hpp

#include "Memory.hpp"
#include <map>
#include <iostream>
#include <string>

class Handler final {
private:
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
	std::map<unsigned int, std::pair<std::string, unsigned long long int>> times;
	void DistribRngSpd(const Memory& memory, const double& instSpd, const unsigned long long int& diffTime);
	void AddTimesStr(const Memory& memory);
	void CalcDiff(unsigned long long int& diffTime, double& diffDist, double& diffElev, double& instSpd, const Point& prevPoint, const Point& currPoint);
public:
	Handler();
	int GetSummTime() const;//s
	double GetDistanñe() const;//m
	double GetAverSpeed() const;//m/s
	int GetMoutTime() const;//s
	int GetStopTime() const;//s
	double GetAverMoutSpeed() const;//m/s
	double GetMaxSpeed() const;//m/s
	double GetMinAltit() const;//m
	double GetMaxAltit() const;//m
	double GetSummAscend() const;//m
	double GetSummDescend() const;//m
	std::map<unsigned int, std::pair<std::string, unsigned long long int>> GetTimes() const;
	void CalcValues(const Memory& memory, double spdThrshld = 0.3);
	
};

#endif