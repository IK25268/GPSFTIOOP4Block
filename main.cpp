#include "Handler.hpp"
#include "RWFile.hpp"
#include "Memory.hpp"

int main() {
    Memory memory;
    memory.AddSpdRange({0.0, 4.0});
    memory.AddSpdRange({5.0, 7.0});
    memory.AddSpdRange({8.0, 20.0});
    RWFile::ReadFile(memory, "input.txt");
    Handler handler;
    handler.CalcValues(memory, 0.3);
    handler.PrintValues();
    return 0;
}