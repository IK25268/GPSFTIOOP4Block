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

void Handler::CalcValues(Memory memory, double spdThrshld)
{
	Point prevPoint = memory.ReturnPoints().front();
	unsigned long long int diffTime = 0;
	double diffDist = 0.0;
	double diffElev = 0.0;
	double instSpd = 0.0;
	minAltit = memory.ReturnPoints().front().GetElevation();
	maxAltit = memory.ReturnPoints().front().GetElevation();
	AddTimesStr(memory);
	for (auto& currPoint : memory.ReturnPoints())
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
		DistribRngSpd(memory, instSpd, diffTime);
		prevPoint = currPoint;
	}
	averSpeed = distanñe / summTime;
	averMoutSpeed = distanñe / moutTime;
}

void Handler::PrintValues()
{
	std::cout << "summTime " << summTime << std::endl;
	std::cout << "distance " << distanñe << std::endl;
	std::cout << "averSpeed " << averSpeed << std::endl;
	std::cout << "moutTime " << moutTime << std::endl;
	std::cout << "stopTime " << stopTime << std::endl;
	std::cout << "averMoutSpeed " << averMoutSpeed << std::endl;
	std::cout << "maxSpeed " << maxSpeed << std::endl;
	std::cout << "minAltit " << minAltit << std::endl;
	std::cout << "maxAltit " << maxAltit << std::endl;
	std::cout << "summAscend " << summAscend << std::endl;
	std::cout << "summDescend " << summDescend << std::endl;
	for (auto& time : times)
	{
		std::cout << "interval from to ";
		std::cout << time.second.first;
		std::cout << " duration ";
		std::cout << time.second.second << std::endl;
	}
}

void Handler::DistribRngSpd(Memory memory, double instSpd, unsigned long long int diffTime)
{
	int j = 0;
	for (auto& interval : memory.ReturnSpeedIntervals())
	{
		if ((instSpd >= interval.second.first) && (instSpd <= interval.second.second)) times[j].second += diffTime;
		j++;
	}
}

void Handler::AddTimesStr(Memory memory)
{
	for (unsigned int i = 0; i < memory.ReturnSpeedIntervals().size(); i++)
	{
		std::string range = std::to_string(memory.ReturnSpeedIntervals()[i].first);
		range += " ";
		range += std::to_string(memory.ReturnSpeedIntervals()[i].second);
		times.insert({ i, {range, 0} });
	}
}

void Handler::CalcDiff(unsigned long long int& diffTime, double& diffDist, double& diffElev, double& instSpd, Point prevPoint, Point currPoint)
{
	diffTime = prevPoint.TimeTo(currPoint);
	diffElev = currPoint.GetElevation() - prevPoint.GetElevation();
	diffDist = prevPoint.DistanceTo(currPoint);
	instSpd = (diffTime == 0.0) ? 0.0 : diffDist / diffTime;
}