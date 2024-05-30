#include "RWFile.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

Memory RWFile::ReadFile(const std::string& inputName)
{
	Memory memory;
	std::fstream fsInput;
	fsInput.open(inputName, std::fstream::in | std::fstream::out | std::fstream::app);
	std::string data = "";
	if (fsInput.is_open())
	{
		while (data.find("<trkseg>") == std::string::npos)
		{
			std::getline(fsInput, data);
		}
		while (!fsInput.eof())
		{
			std::getline(fsInput, data);
			data.erase(0, 2);
			if (strcmp("/trkseg>",data.data()) == 0) break;
			data.erase(0, 12);
			data.erase(data.size() - 2, 2);
			int pos = data.find("lo");
			double lat = atof(data.substr(0, pos-2).data());
			double lon = atof(data.substr(pos+5, data.size()-pos-4).data());
			std::getline(fsInput, data);
			data.erase(0, 11);
			data.erase(data.find("Z</time>"), 8);
			unsigned long long int t = 0;
			t += 31536000 * atoi(data.substr(0, 2).data());
			data.erase(0, 3);
			t += 86400*30 * atoi(data.substr(0, data.find("-")).data());
			data.erase(0, data.find("-")+1);
			t += 86400  * atoi(data.substr(0, data.find("T")).data());
			data.erase(0, data.find("T") + 1);
			t += 3600 * atoi(data.substr(0, data.find(":")).data());
			data.erase(0, data.find(":") + 1);
			t += 60 * atoi(data.substr(0, data.find(":")).data());
			data.erase(0, data.find(":") + 1);
			t += atoi(data.substr(0, data.size()).data());
			std::getline(fsInput, data);
			data.erase(0, 8);
			data.erase(data.size()-6, 6);
			double elev = atof(data.data());
			memory.AddPoint({ lat, lon, elev, t });
			std::getline(fsInput, data);
		}
	}
	fsInput.close();
	return memory;
}

void RWFile::PrintValues(const Handler& handler, const DistribSpd& distribSpd, std::ostream& streamOut)
{
	streamOut << "summTime " << handler.GetSummTime() << std::endl;
	streamOut << "distance " << handler.GetDistanñe() << std::endl;
	streamOut << "averSpeed " << handler.GetAverSpeed() << std::endl;
	streamOut << "moutTime " << handler.GetMoutTime() << std::endl;
	streamOut << "stopTime " << handler.GetStopTime() << std::endl;
	streamOut << "averMoutSpeed " << handler.GetAverMoutSpeed() << std::endl;
	streamOut << "maxSpeed " << handler.GetMaxSpeed() << std::endl;
	streamOut << "minAltit " << handler.GetMinAltit() << std::endl;
	streamOut << "maxAltit " << handler.GetMaxAltit() << std::endl;
	streamOut << "summAscend " << handler.GetSummAscend() << std::endl;
	streamOut << "summDescend " << handler.GetSummDescend() << std::endl;
	for (auto& time : distribSpd.GetTimes())
	{
		streamOut << "interval from to ";
		streamOut << time.first;
		streamOut << " duration ";
		streamOut << time.second << std::endl;
	}
}