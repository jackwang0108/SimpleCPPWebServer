#include "serverCommon.h"
#include "gtest/gtest.h"

#define TestSuiteName serverStringTest

using std::string;

int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(TestSuiteName, ltrimCharStringSpace) {
	char src[] = "   12345";
	char dst[] = "12345";
	EXPECT_STREQ(idc::ltrim(src), dst);
}

TEST(TestSuiteName, ltrimCharStringAny) {
	char src[] = "____12345";
	char dst[] = "12345";
	EXPECT_STREQ(idc::ltrim(src, '_'), dst);
}


TEST(TestSuiteName, rtrimCharStringSpace) {
	char src[] = "12345    ";
	char dst[] = "12345";
	EXPECT_STREQ(idc::rtrim(src), dst);
}

TEST(TestSuiteName, rtrimCharStringAny) {
	char src[] = "12345_____";
	char dst[] = "12345";
	EXPECT_STREQ(idc::rtrim(src, '_'), dst);
}

TEST(TestSuiteName, trimCharStringSpace) {
	char src[] = "   12345    ";
	char dst[] = "12345";
	EXPECT_STREQ(idc::trim(src), dst);
}

TEST(TestSuiteName, trimCharStringAny) {
	char src[] = "_____12345____";
	char dst[] = "12345";
	EXPECT_STREQ(idc::trim(src, '_'), dst);
}


TEST(TestSuiteName, ltrimStringSpace) {
	string src = "   12345";
	string dst = "12345";
	EXPECT_EQ(idc::ltrim(src), dst);
}

TEST(TestSuiteName, ltrimStringAny) {
	string src = "+++12345";
	string dst = "12345";
	EXPECT_EQ(idc::ltrim(src, '+'), dst);
}

TEST(TestSuiteName, rtrimStringSpace) {
	string src = "12345    ";
	string dst = "12345";
	EXPECT_EQ(idc::rtrim(src), dst);
}

TEST(TestSuiteName, rtrimStringAny) {
	string src = "12345++++";
	string dst = "12345";
	EXPECT_EQ(idc::rtrim(src, '+'), dst);
}


TEST(TestSuiteName, rimStringSpace) {
	string src = "   12345";
	string dst = "12345";
	EXPECT_EQ(idc::trim(src), dst);
}

TEST(TestSuiteName, trimStringAny) {
	string src = "+++12345+++++";
	string dst = "12345";
	EXPECT_EQ(idc::trim(src, '+'), dst);
}

TEST(TestSuiteName, toUpperCharString) {
	char src[] = "abcDef";
	char dst[] = "ABCDEF";
	EXPECT_STREQ(idc::toUpper(src), dst);
}

TEST(TestSuiteName, toUpperString) {
	string src = "abcDef";
	string dst = "ABCDEF";
	EXPECT_EQ(idc::toUpper(src), dst);
}

TEST(TestSuiteName, toLowerCharString) {
	char src[] = "ABCdEF";
	char dst[] = "abcdef";
	EXPECT_STREQ(idc::toLower(src), dst);
}

TEST(TestSuiteName, toLowerString) {
	string src = "ABCdEF";
	string dst = "abcdef";
	EXPECT_EQ(idc::toLower(src), dst);
}