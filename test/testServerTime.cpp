#include "serverCommon.h"
#include "gtest/gtest.h"

#define TestSuiteName serverTimeTest

int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


TEST(TestSuiteName, t1) {
	EXPECT_EQ(1, 1);
}