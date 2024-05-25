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

void RWFile::PrintValues(const Handler& handler)
{
	std::cout << "summTime " << handler.GetSummTime() << std::endl;
	std::cout << "distance " << handler.GetDistanñe() << std::endl;
	std::cout << "averSpeed " << handler.GetAverSpeed() << std::endl;
	std::cout << "moutTime " << handler.GetMoutTime() << std::endl;
	std::cout << "stopTime " << handler.GetStopTime() << std::endl;
	std::cout << "averMoutSpeed " << handler.GetAverMoutSpeed() << std::endl;
	std::cout << "maxSpeed " << handler.GetMaxSpeed() << std::endl;
	std::cout << "minAltit " << handler.GetMinAltit() << std::endl;
	std::cout << "maxAltit " << handler.GetMaxAltit() << std::endl;
	std::cout << "summAscend " << handler.GetSummAscend() << std::endl;
	std::cout << "summDescend " << handler.GetSummDescend() << std::endl;
	for (auto& time : handler.GetTimes())
	{
		std::cout << "interval from to ";
		std::cout << time.second.first;
		std::cout << " duration ";
		std::cout << time.second.second << std::endl;
	}
}