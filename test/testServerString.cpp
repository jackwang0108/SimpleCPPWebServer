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

TEST(TestSuiteName, replaceString1) {
	string str = "Name=jack, age=23, sex=male";
	string from = "=";
	string to = ":";
	string expected = "Name:jack, age:23, sex:male";
	EXPECT_TRUE(idc::replace(str, from, to));
	EXPECT_EQ(str, expected);
}


TEST(TestSuiteName, replaceString2) {
	string str = "Name:::jack, age:::23, sex:::male";
	string from = "::";
	string to = ":";
	string expected = "Name:jack, age:23, sex:male";
	EXPECT_TRUE(idc::replace(str, from, to, true));
	EXPECT_EQ(str, expected);
}


TEST(TestSuiteName, replaceString3) {
	string str = "Name:jack, age:23, sex:male";
	string from = ":";
	string to = "::";
	EXPECT_FALSE(idc::replace(str, from, to, true));
}


TEST(TestSuiteName, replaceString4) {
	string str = "Name:jack, age:23, sex:male";
	string from = "=";
	string to = ":";
	string expected = "Name:jack, age:23, sex:male";
	EXPECT_TRUE(idc::replace(str, from, to));
	EXPECT_EQ(str, expected);
}

TEST(TestSuiteName, replaceString5) {
	string str = "Name:jack, age:23, sex:male";
	string from = ":";
	string to = "==";
	string expected = "Name==jack, age==23, sex==male";
	EXPECT_TRUE(idc::replace(str, from, to));
	EXPECT_EQ(str, expected);
}

TEST(TestSuiteName, replaceString7) {
	string str = "Name: jack, age: 23, sex: male";
	string from = ":";
	string to = "";
	string expected = "Name jack, age 23, sex male";
	EXPECT_TRUE(idc::replace(str, from, to));
	EXPECT_EQ(str, expected);
}

TEST(TestSuiteName, replaceCharString1) {
	char str[] = "Name=jack, age=23, sex=male";
	string from = "=";
	string to = ":";
	char expected[] = "Name:jack, age:23, sex:male";
	EXPECT_TRUE(idc::replace(str, from, to));
	EXPECT_STREQ(str, expected);
}

TEST(TestSuiteName, replaceCharString2) {
	char str[] = "Name:::jack, age:::23, sex:::male";
	string from = "::";
	string to = ":";
	char expected[] = "Name:jack, age:23, sex:male";
	EXPECT_TRUE(idc::replace(str, from, to, true));
	EXPECT_STREQ(str, expected);
}

TEST(TestSuiteName, replaceCharString3) {
	char str[] = "Name:jack, age:23, sex:male";
	string from = ":";
	string to = "==";
	char expected[] = "Name==jack, age==23, sex==male";
	idc::replace(str, from, to, true);
	// EXPECT_THROW(idc::replace(str, from, to, true), B);
	EXPECT_STREQ(str, expected);
}

TEST(TestSuiteName, extractNumber1) {
	string src = "abc123";
	string dst;
	string expected = "123";
	EXPECT_EQ(idc::extractNumber(src, dst), expected);
}

TEST(TestSuiteName, extractNumber2) {
	string src = "abc-123.12";
	string dst;
	string expected = "-123.12";
	EXPECT_EQ(idc::extractNumber(src, dst, true, true), expected);
}

TEST(TestSuiteName, extractNumber3) {
	string src = "abc-123.12";
	char dst[20];
	char expected[] = "-123.12";
	EXPECT_STREQ(idc::extractNumber(src, dst, true, true), expected);
}

TEST(TestSuiteName, extractNumber4) {
	string src = "abc-123.12";
	string expected = "-123.12";
	EXPECT_EQ(idc::extractNumber(src, true, true), expected);
}