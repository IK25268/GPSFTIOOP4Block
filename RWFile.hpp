#ifndef __RWFile_hpp
#define __RWFile_hpp
#include <fstream>
#include <iostream>
#include "Memory.hpp"

class RWFile final {
private:
public:
	static void ReadFile(Memory& memory, const char* inputName);
};

#endif