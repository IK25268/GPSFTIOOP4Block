#include "Handler.hpp"
#include "RWFile.hpp"

int main() {
    Handler handler;
    RWFile::ReadFile(handler, "input.txt");
    std::list<std::pair<std::pair<double, double>, unsigned long long int>> speedIntervals = {};
    speedIntervals.push_back({{0.0, 0.1}, 0});
    handler.CalcValues(speedIntervals);
    handler.PrintValues();
    return 0;
}