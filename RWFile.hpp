#ifndef __RWFile_hpp
#define __RWFile_hpp
#include <fstream>
#include <iostream>
#include "Memory.hpp"
#include "Handler.hpp"

class RWFile final {
private:
public:
	static Memory ReadFile(const std::string& inputName);
	static void PrintValues(const Handler& handler);
};

#endif