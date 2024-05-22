#include "Handler.hpp"

std::list<Point>& Handler::GetPoints()
{
	return points;
}

int Handler::GetSummTime()
{
	return summTime;
}

double Handler::GetDistanñe()
{
	return distanñe;
}

double Handler::GetAverSpeed()
{
	return averSpeed;
}

int Handler::GetMoutTime()
{
	return moutTime;
}

int Handler::GetStopTime()
{
	return stopTime;
}

double Handler::GetAverMoutSpeed()
{
	return averMoutSpeed;
}

double Handler::GetMaxSpeed()
{
	return maxSpeed;
}

double Handler::GetMinAltit()
{
	return minAltit;
}

double Handler::GetMaxAltit()
{
	return maxAltit;
}

double Handler::GetSummAscend()
{
	return summAscend;
}

double Handler::GetSummDescend()
{
	return summDescend;
}

void Handler::CalcValues(std::list<std::pair<std::pair<double, double>, unsigned long long int>> speedIntervals)
{
	unsigned long long int diffTime = 0;
	double diffDist = 0.0;
	double diffElev = 0.0;
	double prevElev = points.front().GetElevation();
	unsigned long long int prevTime = points.front().GetTime();
	double prevLat = points.front().GetLatitude();
	double prevLon = points.front().GetLongitude();	
	double instSpd = 0.0;

	maxSpeed = 0.0;
	minAltit = points.front().GetElevation();
	maxAltit = points.front().GetElevation();
	for (auto& interval : speedIntervals)
	{
		interval.second = 0;
	}
	for (auto& iter : points)
	{
		diffTime += iter.GetTime() - prevTime;
		summTime += diffTime;
		prevTime = iter.GetTime();

		diffDist += sqrt(pow((iter.GetLatitude()-prevLat), 2) + pow((iter.GetLongitude() - prevLon), 2));
		distanñe += diffDist;
		prevLat = iter.GetLatitude();
		prevLon = iter.GetLongitude();

		if (diffDist < 0.01) stopTime += diffTime;
		else moutTime += diffTime;

		instSpd = diffDist / diffTime;

		if (instSpd > maxSpeed) maxSpeed = instSpd;
		if (iter.GetElevation() > maxAltit) maxAltit = iter.GetElevation();
		if (iter.GetElevation() < minAltit) minAltit = iter.GetElevation();

		diffElev = iter.GetElevation() - prevElev;
		if (diffElev > 0.0) summAscend += diffElev;
		if (diffElev < 0.0) summDescend += abs(diffElev);
		for (auto& interval : speedIntervals)
		{
			if ((instSpd >= interval.first.first) && (instSpd <= interval.first.second)) interval.second += diffTime;
		}
	}
	averSpeed = distanñe / summTime;
	averMoutSpeed = distanñe / moutTime;
	std::cout << std::endl;
}

void Handler::PrintValues()
{
	std::cout << "summTime " << GetSummTime() << std::endl;
	std::cout << "distanñe " << GetDistanñe() << std::endl;
	std::cout << "averSpeed " << GetAverSpeed() << std::endl;
	std::cout << "moutTime " << GetMoutTime() << std::endl;
	std::cout << "stopTime " << GetStopTime() << std::endl;
	std::cout << "averMoutSpeed " << GetAverMoutSpeed() << std::endl;
	std::cout << "maxSpeed " << GetMaxSpeed() << std::endl;
	std::cout << "minAltit " << GetMinAltit() << std::endl;
	std::cout << "maxAltit " << GetMaxAltit() << std::endl;
	std::cout << "summAscend " << GetSummAscend() << std::endl;
	std::cout << "summDescend " << GetSummDescend() << std::endl;
}

std::list<std::pair<std::pair<double, double>, unsigned long long int>> Handler::GetSpeedIntervals()
{
	return speedIntervals;
}
