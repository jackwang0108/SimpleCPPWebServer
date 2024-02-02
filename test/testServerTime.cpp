#include "serverCommon.h"
#include "gtest/gtest.h"

#define TestSuiteName serverTimeTest

int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

using std::cout;
using std::string;

std::time_t now = 1706861110;

TEST(TestSuiteName, timeToStr1) {
	string nowStr = idc::timeToStr(now);

	::testing::internal::CaptureStdout();
	cout.imbue(std::locale("en_US.utf8"));
	cout << nowStr;
	string output = ::testing::internal::GetCapturedStdout();

	string expected = "2024-02-02 16:05:10";
	EXPECT_EQ(output, expected);
}

TEST(TestSuiteName, timeToStr2) {
	chrono::time_point nowTP = chrono::system_clock::from_time_t(now);

	string nowStr = idc::timeToStr(nowTP);
	::testing::internal::CaptureStdout();
	cout.imbue(std::locale("en_US.utf8"));
	cout << nowStr;
	string output = ::testing::internal::GetCapturedStdout();

	string expected = "2024-02-02 16:05:10";
	EXPECT_EQ(output, expected);
}

TEST(TestSuiteName, getCurrTime) {
	string result1, result2 = idc::getCurrTime();
	idc::getCurrTime(result1);
	EXPECT_EQ(result1, result2);
}

TEST(TestSuiteName, strToTime) {
	string timeStr = idc::timeToStr(now);
	time_t time = idc::strToTime(timeStr);
	EXPECT_EQ(time, now);
}

TEST(TestSuiteName, strTimeCalculation1) {
	time_t after = now + 10;
	string nowStr = idc::timeToStr(now);
	string afterStr = idc::timeToStr(after);
	string calculated = idc::strTimeCalculation(nowStr, 10);
	EXPECT_EQ(afterStr, calculated);
}

TEST(TestSuiteName, strTimeCalculation2) {
	time_t after = now + 60;
	string nowStr = idc::timeToStr(now);
	string afterStr = idc::timeToStr(after);
	string calculated = idc::strTimeCalculation(nowStr, 1min);
	EXPECT_EQ(afterStr, calculated);
}