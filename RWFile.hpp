#ifndef __RWFile_hpp
#define __RWFile_hpp
#include <fstream>
#include <iostream>
#include "Memory.hpp"
#include "Handler.hpp"
#include "DistribSpd.hpp"

class RWFile final {
private:
	RWFile();
	RWFile(const RWFile& rWFile);
public:
	static Memory ReadFile(const std::string& inputName);
	static void PrintValues(const Handler& handler, const DistribSpd& distribSpd, std::ostream& streamOut);
};

#endif