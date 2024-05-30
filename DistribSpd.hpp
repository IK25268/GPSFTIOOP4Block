#ifndef __DistribSpd_hpp
#define __DistribSpd_hpp

#include "Memory.hpp"
#include "DistribSpd.hpp"
#include <map>
#include <iostream>
#include <string>

class DistribSpd final {
private:
	std::vector<std::pair<std::string, unsigned long long int>> times;
	void AddTimesStr(const Memory& memory);
public:
	void CalcRngSpd(const Memory& memory);
	std::vector<std::pair<std::string, unsigned long long int>> GetTimes() const;
};

#endif
