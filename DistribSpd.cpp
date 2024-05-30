#include "DistribSpd.hpp"

std::vector<std::pair<std::string, unsigned long long int>> DistribSpd::GetTimes() const
{
	return times;
}

void DistribSpd::AddTimesStr(const Memory& memory)
{
	for (auto& interval : memory.GetSpeedIntervals())
	{
		std::string range = std::to_string(interval.first);
		range += " ";
		range += std::to_string(interval.second);
		times.push_back({ range, 0 });
	}
}

void DistribSpd::CalcRngSpd(const Memory& memory)
{
	AddTimesStr(memory);
	Point prevPoint = memory.GetPoints().front();
	double instSpd = 0.0;
	unsigned long long int diffTime = 0;
	double diffDist = 0.0;
	for (const auto& currPoint : memory.GetPoints())
	{
		diffTime = prevPoint.TimeTo(currPoint);
		diffDist = prevPoint.DistanceTo(currPoint);
		instSpd = (diffTime == 0.0) ? 0.0 : diffDist / diffTime;
		for (unsigned int i = 0; i < memory.GetSpeedIntervals().size(); i++)
		{
			if ((instSpd >= memory.GetSpeedIntervals()[i].first) && (instSpd <= memory.GetSpeedIntervals()[i].second)&&(instSpd != 0.0)) times[i].second += diffTime;
		}
		prevPoint = currPoint;
	}
}