#include "pch.h"
#include "../GPSFTIOOP4Block/Memory.hpp"
#include "../GPSFTIOOP4Block/RWFile.hpp"
#include "../GPSFTIOOP4Block/Handler.hpp"
#include "../GPSFTIOOP4Block/Memory.cpp"
#include "../GPSFTIOOP4Block/RWFile.cpp"
#include "../GPSFTIOOP4Block/Handler.cpp"
#include "../GPSFTIOOP4Block/Point.cpp"
#include "../GPSFTIOOP4Block/Point.hpp"

TEST(TestCalcValues, TestDistance) {
	
	Memory memory = RWFile::ReadFile("input.txt");
	Handler handler;
	handler.CalcValues(memory, 0.3);
	ASSERT_STREQ(std::to_string(handler.GetDistanñe()).data(), "11808.739638");
}

TEST(TestCalcValues, TestAverSpeed) {
	
	Memory memory = RWFile::ReadFile("input.txt");
	Handler handler;
	handler.CalcValues(memory, 0.3);
	ASSERT_STREQ(std::to_string(handler.GetAverSpeed()).data(), "2.986530");
}

TEST(TestCalcValues, TestMoutTime) {
	
	Memory memory = RWFile::ReadFile("input.txt");
	Handler handler;
	handler.CalcValues(memory, 0.3);
	ASSERT_STREQ(std::to_string(handler.GetMoutTime()).data(), "3899");
}

TEST(TestCalcValues, TestStopTime) {
	
	Memory memory = RWFile::ReadFile("input.txt");
	Handler handler;
	handler.CalcValues(memory, 0.3);
	ASSERT_STREQ(std::to_string(handler.GetStopTime()).data(), "55");
}

TEST(TestCalcValues, TestAverMoutSpeed) {
	
	Memory memory = RWFile::ReadFile("input.txt");
	Handler handler;
	handler.CalcValues(memory, 0.3);
	ASSERT_STREQ(std::to_string(handler.GetAverMoutSpeed()).data(), "3.028659");
}

TEST(TestCalcValues, TestMaxSpeed) {
	
	Memory memory = RWFile::ReadFile("input.txt");
	Handler handler;
	handler.CalcValues(memory, 0.3);
	ASSERT_STREQ(std::to_string(handler.GetMaxSpeed()).data(), "10.600183");
}

TEST(TestCalcValues, TestMinAltit) {
	
	Memory memory = RWFile::ReadFile("input.txt");
	Handler handler;
	handler.CalcValues(memory, 0.3);
	ASSERT_STREQ(std::to_string(handler.GetMinAltit()).data(), "544.372799");
}

TEST(TestCalcValues, TestMaxAltit) {
	
	Memory memory = RWFile::ReadFile("input.txt");
	Handler handler;
	handler.CalcValues(memory, 0.3);
	ASSERT_STREQ(std::to_string(handler.GetMaxAltit()).data(), "605.332799");
}

TEST(TestCalcValues, TestSummAscend) {
	
	Memory memory = RWFile::ReadFile("input.txt");
	Handler handler;
	handler.CalcValues(memory, 0.3);
	ASSERT_STREQ(std::to_string(handler.GetSummAscend()).data(), "508.711199");
}

TEST(TestCalcValues, TestSummDescend) {
	
	Memory memory = RWFile::ReadFile("input.txt");
	Handler handler;
	handler.CalcValues(memory, 0.3);
	ASSERT_STREQ(std::to_string(handler.GetSummDescend()).data(), "495.299999");
}

TEST(TestCalcValues, TestDistribSpd) {
	
	Memory memory = RWFile::ReadFile("input.txt");
	memory.AddSpdRange({ 0.0, 4.0 });
	memory.AddSpdRange({ 5.0, 7.0 });
	memory.AddSpdRange({ 8.0, 20.0 });
	Handler handler;
	handler.CalcValues(memory, 0.3);
	ASSERT_EQ(handler.GetTimes()[0].second, 3057);
	ASSERT_EQ(handler.GetTimes()[1].second, 394);
	ASSERT_EQ(handler.GetTimes()[2].second, 14);
}