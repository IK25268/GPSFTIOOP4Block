#ifndef __RWFile_hpp
#define __RWFile_hpp
#include <fstream>
#include <iostream>
#include "Handler.hpp"

class RWFile final {
private:
public:
	static void ReadFile(Handler& handler, const char* inputName);
};

#endif