#include "serverCommon.h"
#include "gtest/gtest.h"

#define TestSuiteName serverStringTest

using std::string;
using std::vector;

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

TEST(TestSuiteName, matchStr1) {
	EXPECT_TRUE(idc::matchStr("test.cpp", ".*\\.(h|cpp)"));
}

TEST(TestSuiteName, StrSpliter1) {
	idc::StrSpliter test("a,b,c,d,e,f", ",");
	vector<string> re{"a", "b", "c", "d", "e", "f"};
	for (int i = 0; i < re.size(); i++)
		EXPECT_EQ(re[i], test[i]);
}

TEST(TestSuiteName, StrSpliter2) {
	idc::StrSpliter test("a, b ,   c ,  d ,  e,  f", ",", true);
	vector<string> re{"a", "b", "c", "d", "e", "f"};
	for (int i = 0; i < re.size(); i++)
		EXPECT_EQ(re[i], test[i]);
}

TEST(TestSuiteName, StrSplit3) {
	idc::StrSpliter test = idc::StrSpliter::split("a+a+a+a+a", "+");
	vector<string> re{"a", "a", "a", "a", "a"};
	for (int i = 0; i < re.size(); i++)
		EXPECT_EQ(re[i], test[i]);
}

TEST(TestSuiteName, StrSplit4) {
	idc::StrSpliter test("a b c d e f", " ");
	::testing::internal::CaptureStdout();
	std::cout << test << "\n";
	string output = ::testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "{ a, b, c, d, e, f }\n");
}

TEST(TestSuiteName, StrSplit5) {
	idc::StrSpliter test("21, -12, 3.14, hello", ",", true);
	EXPECT_EQ(test.getValue<int>(0), 21);
	EXPECT_EQ(test.getValue<int>(1), -12);
	EXPECT_FLOAT_EQ(test.getValue<float>(2), 3.14);
	char buf[1024];
	EXPECT_STREQ(test.getValue(3, buf), "hello");
	EXPECT_EQ(test.getValue<string>(3), "hello");
}