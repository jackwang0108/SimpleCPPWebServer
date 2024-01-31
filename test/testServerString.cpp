#include "serverCommon.h"
#include "gtest/gtest.h"

using std::string;

int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(serverStringTest, ltrimCharStringSpace) {
	char src[] = "   12345";
	char dst[] = "12345";
	EXPECT_STREQ(idc::ltrim(src), dst);
}

TEST(serverStringTest, ltrimCharStringAny) {
	char src[] = "____12345";
	char dst[] = "12345";
	EXPECT_STREQ(idc::ltrim(src, '_'), dst);
}


TEST(serverStringTest, rtrimCharStringSpace) {
	char src[] = "12345    ";
	char dst[] = "12345";
	EXPECT_STREQ(idc::rtrim(src), dst);
}

TEST(serverStringTest, rtrimCharStringAny) {
	char src[] = "12345_____";
	char dst[] = "12345";
	EXPECT_STREQ(idc::rtrim(src, '_'), dst);
}

TEST(serverStringTest, trimCharStringSpace) {
	char src[] = "   12345    ";
	char dst[] = "12345";
	EXPECT_STREQ(idc::trim(src), dst);
}

TEST(serverStringTest, trimCharStringAny) {
	char src[] = "_____12345____";
	char dst[] = "12345";
	EXPECT_STREQ(idc::trim(src, '_'), dst);
}


TEST(serverStringTest, ltrimStringSpace) {
	string src = "   12345";
	string dst = "12345";
	EXPECT_EQ(idc::ltrim(src), dst);
}

TEST(serverStringTest, ltrimStringAny) {
	string src = "+++12345";
	string dst = "12345";
	EXPECT_EQ(idc::ltrim(src, '+'), dst);
}

TEST(serverStringTest, rtrimStringSpace) {
	string src = "12345    ";
	string dst = "12345";
	EXPECT_EQ(idc::rtrim(src), dst);
}

TEST(serverStringTest, rtrimStringAny) {
	string src = "12345++++";
	string dst = "12345";
	EXPECT_EQ(idc::rtrim(src, '+'), dst);
}


TEST(serverStringTest, rimStringSpace) {
	string src = "   12345";
	string dst = "12345";
	EXPECT_EQ(idc::trim(src), dst);
}

TEST(serverStringTest, trimStringAny) {
	string src = "+++12345+++++";
	string dst = "12345";
	EXPECT_EQ(idc::trim(src, '+'), dst);
}