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
    DistribSpd distribSpd;
    distribSpd.CalcRngSpd(memory);
    RWFile::PrintValues(handler, distribSpd, std::cout);
    std::ofstream out;
    out.open("out.txt");
    if (out.is_open()) RWFile::PrintValues(handler, distribSpd, out);
    out.close();
    return 0;
}