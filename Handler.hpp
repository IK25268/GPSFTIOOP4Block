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
	void DistribRngSpd(Memory memory, double instSpd, unsigned long long int diffTime);
	void AddTimesStr(Memory memory);
	void CalcDiff(unsigned long long int& diffTime, double& diffDist, double& diffElev, double& instSpd, Point prevPoint, Point currPoint);
public:
	Handler();
	void CalcValues(Memory memory, double spdThrshld = 0.3);
	void PrintValues();
};

#endif