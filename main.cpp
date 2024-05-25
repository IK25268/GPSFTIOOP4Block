#include "Handler.hpp"
#include "RWFile.hpp"
#include "Memory.hpp"

int main() {
    Memory memory = RWFile::ReadFile("input.txt");
    memory.AddSpdRange({0.0, 4.0});
    memory.AddSpdRange({5.0, 7.0});
    memory.AddSpdRange({8.0, 20.0});
    Handler handler;
    handler.CalcValues(memory, 0.3);
    RWFile::PrintValues(handler);
    return 0;
}