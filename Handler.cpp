#include "Handler.hpp"

Handler::Handler()
{
	summTime = 0;//s
	distan�e = 0.0;//m
	averSpeed = 0.0;//m/s
	moutTime = 0;//s
	stopTime = 0;//s
	averMoutSpeed = 0.0;//m/s
	maxSpeed = 0.0;//m/s
	minAltit =  0.0;//m
	maxAltit = 0.0;//m
	summAscend = 0.0;//m
	summDescend = 0.0;//m
}

void Handler::CalcValues(const Memory& memory, double spdThrshld)
{
	Point prevPoint = memory.GetPoints().front();
	unsigned long long int diffTime = 0;
	double diffDist = 0.0;
	double diffElev = 0.0;
	double instSpd = 0.0;
	minAltit = memory.GetPoints().front().GetElevation();
	maxAltit = memory.GetPoints().front().GetElevation();
	AddTimesStr(memory);
	for (auto& currPoint : memory.GetPoints())
	{
		CalcDiff(diffTime, diffDist, diffElev, instSpd, prevPoint, currPoint);
		summTime += diffTime;
		distan�e += diffDist;
		if (instSpd < spdThrshld) stopTime += diffTime;
		else moutTime += diffTime;
		if (instSpd > maxSpeed) maxSpeed = instSpd;
		if (currPoint.GetElevation() > maxAltit) maxAltit = currPoint.GetElevation();
		if (currPoint.GetElevation() < minAltit) minAltit = currPoint.GetElevation();
		if (diffElev > 0.0) summAscend += diffElev;
		if (diffElev < 0.0) summDescend += abs(diffElev);
		DistribRngSpd(memory, instSpd, diffTime);
		prevPoint = currPoint;
	}
	averSpeed = distan�e / summTime;
	averMoutSpeed = distan�e / moutTime;
}

int Handler::GetSummTime() const
{
	return summTime;
}

double Handler::GetDistan�e() const
{
	return distan�e;
}

double Handler::GetAverSpeed() const
{
	return averSpeed;
}

int Handler::GetMoutTime() const
{
	return moutTime;
}

void Handler::DistribRngSpd(const Memory& memory, const double& instSpd, const unsigned long long int& diffTime)
{
	int j = 0;
	for (auto& interval : memory.GetSpeedIntervals())
	{
		if ((instSpd >= interval.second.first) && (instSpd <= interval.second.second)) times[j].second += diffTime;
		j++;
	}
}

void Handler::AddTimesStr(const Memory& memory)
{
	for (unsigned int i = 0; i < memory.GetSpeedIntervals().size(); i++)
	{
		std::string range = std::to_string(memory.GetSpeedIntervals()[i].first);
		range += " ";
		range += std::to_string(memory.GetSpeedIntervals()[i].second);
		times.insert({ i, {range, 0} });
	}
}

void Handler::CalcDiff(unsigned long long int& diffTime, double& diffDist, double& diffElev, double& instSpd, const Point& prevPoint, const Point& currPoint)
{
	diffTime = prevPoint.TimeTo(currPoint);
	diffElev = currPoint.GetElevation() - prevPoint.GetElevation();
	diffDist = prevPoint.DistanceTo(currPoint);
	instSpd = (diffTime == 0.0) ? 0.0 : diffDist / diffTime;
}

int Handler::GetStopTime() const
{
	return stopTime;
}

double Handler::GetAverMoutSpeed() const
{
	return averMoutSpeed;
}

double Handler::GetMaxSpeed() const
{
	return maxSpeed;
}

double Handler::GetMinAltit() const
{
	return minAltit;
}

double Handler::GetMaxAltit() const
{
	return maxAltit;
}

double Handler::GetSummAscend() const
{
	return summAscend;
}

double Handler::GetSummDescend() const
{
	return summDescend;
}

std::map<unsigned int, std::pair<std::string, unsigned long long int>> Handler::GetTimes() const
{
	return times;
}