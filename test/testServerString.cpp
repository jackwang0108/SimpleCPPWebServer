#include "serverString.h"
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
	idc::StrSplitter test("a,b,c,d,e,f", ",");
	vector<string> re{"a", "b", "c", "d", "e", "f"};
	for (int i = 0; i < re.size(); i++)
		EXPECT_EQ(re[i], test[i]);
}

TEST(TestSuiteName, StrSpliter2) {
	idc::StrSplitter test("a, b ,   c ,  d ,  e,  f", ",", true);
	vector<string> re{"a", "b", "c", "d", "e", "f"};
	for (int i = 0; i < re.size(); i++)
		EXPECT_EQ(re[i], test[i]);
}

TEST(TestSuiteName, StrSplit3) {
	idc::StrSplitter test = idc::StrSplitter("a-+-a-+-a-+-a-+-a", "-+-");
	vector<string> re{"a", "a", "a", "a", "a"};
	for (int i = 0; i < re.size(); i++)
		EXPECT_EQ(re[i], test[i]);
}

TEST(TestSuiteName, StrSplit4) {
	idc::StrSplitter test("a b c d e f", " ");
	::testing::internal::CaptureStdout();
	std::cout << test << "\n";
	string output = ::testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "{a, b, c, d, e, f}\n");
}

TEST(TestSuiteName, StrSplit5) {
	idc::StrSplitter test("21, -12, 3.14, hello, a30, xx3.14", ",", true);
	EXPECT_EQ(test.getValue<int>(0), 21);
	EXPECT_EQ(test.getValue<int>(1), -12);
	EXPECT_FLOAT_EQ(test.getValue<float>(2), 3.14);
	char buf[1024];
	EXPECT_STREQ(test.getValue(3, buf), "hello");
	EXPECT_EQ(test.getValue<string>(3), "hello");
	EXPECT_EQ(test.getValue<int>(4), 30);
	EXPECT_FLOAT_EQ(test.getValue<float>(5), 3.14);
}

struct SoccerPlayer {
	int no;
	int age;
	int salary;
	string name;
	float weight;
	bool striker;
	string club;
};

SoccerPlayer messi{
    .no = 10,
    .age = 30,
    .salary = 21000,
    .name = "messi",
    .weight = 68.5,
    .striker = true,
    .club = "Barcelona",
};

std::ostream &operator<<(std::ostream &os, SoccerPlayer &sp) {
	os << sp.no << ", ";
	os << sp.age << ", ";
	os << sp.salary << ", ";
	os << sp.name << ", ";
	os << sp.weight << ", ";
	os << sp.striker << ", ";
	os << sp.club << "\n";
	return os;
}

TEST(TestSuiteName, StrSplit6) {
	std::stringstream ssMessi;
	ssMessi << messi;
	idc::StrSplitter words(ssMessi.str(), ",", true);

	SoccerPlayer who;
	words.getValue(0, who.no);
	words.getValue(1, who.age);
	words.getValue(2, who.salary);
	words.getValue(3, who.name);
	words.getValue(4, who.weight);
	words.getValue(5, who.striker);
	words.getValue(6, who.club);

	std::stringstream ssWho;
	ssWho << who;
	EXPECT_EQ(ssMessi.str(), ssWho.str());
}

TEST(TestSuiteName, StrSplit7) {
	idc::StrSplitter ss("test, a", ",", true);
	ss.resplit("test, b", ",", true);
	::testing::internal::CaptureStdout();
	std::cout << ss << "\n";
	string output = ::testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "{test, b}\n");
}

TEST(TestSuiteName, getXmlFieldValue) {
	string xml = "<name>messi</name><no>10</no><age>30</age><salary>21000</salary><weight>68.5</weight><striker>1</striker><club>Barcelona</club>";
	SoccerPlayer who;
	idc::getXmlFieldValue(xml, "name", who.name);
	idc::getXmlFieldValue(xml, "no", who.no);
	idc::getXmlFieldValue(xml, "age", who.age);
	idc::getXmlFieldValue(xml, "salary", who.salary);
	idc::getXmlFieldValue(xml, "weight", who.weight);
	idc::getXmlFieldValue(xml, "striker", who.striker);
	idc::getXmlFieldValue(xml, "club", who.club);

	std::stringstream ssMessi;
	ssMessi << messi;
	idc::StrSplitter words(ssMessi.str(), ",", true);

	std::stringstream ssWho;
	ssWho << who;
	EXPECT_EQ(ssMessi.str(), ssWho.str());
}