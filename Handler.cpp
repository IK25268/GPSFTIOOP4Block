#include "Handler.hpp"

Handler::Handler()
{
	summTime = 0;//s
	distanñe = 0.0;//m
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
	for (auto& currPoint : memory.GetPoints())
	{
		CalcDiff(diffTime, diffDist, diffElev, instSpd, prevPoint, currPoint);
		summTime += diffTime;
		distanñe += diffDist;
		if (instSpd < spdThrshld) stopTime += diffTime;
		else moutTime += diffTime;
		if (instSpd > maxSpeed) maxSpeed = instSpd;
		if (currPoint.GetElevation() > maxAltit) maxAltit = currPoint.GetElevation();
		if (currPoint.GetElevation() < minAltit) minAltit = currPoint.GetElevation();
		if (diffElev > 0.0) summAscend += diffElev;
		if (diffElev < 0.0) summDescend += abs(diffElev);
		prevPoint = currPoint;
	}
	averSpeed = distanñe / summTime;
	averMoutSpeed = distanñe / moutTime;
}

int Handler::GetSummTime() const
{
	return summTime;
}

double Handler::GetDistanñe() const
{
	return distanñe;
}

double Handler::GetAverSpeed() const
{
	return averSpeed;
}

int Handler::GetMoutTime() const
{
	return moutTime;
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