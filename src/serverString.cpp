#include "serverCommon.h"

using std::string;

char *idc::ltrim(char *str, const char c) {
	if (str == nullptr)
		return nullptr;

	char *p = str;
	while (*p == c)
		p++;
	memmove(str, p, strlen(str) - (p - str) + 1);
	return str;
}

char *idc::rtrim(char *str, const char c) {
	if (str == nullptr)
		return nullptr;

	char *p = str + strlen(str) - 1;
	while (*p == c)
		p--;
	*(p + 1) = 0;
	return str;
}

char *idc::trim(char *str, const char c) {
	idc::ltrim(str, c);
	idc::rtrim(str, c);
	return str;
}

string &idc::ltrim(string &str, const char c) {
	std::function<bool(char)> functor = [c](char ch) { return ch != c; };
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), functor));
	return str;
}

string &idc::rtrim(string &str, const char c) {
	std::function<bool(char)> functor = [c](char ch) { return ch != c; };
	str.erase(std::find_if(str.rbegin(), str.rend(), functor).base(), str.end());
	return str;
}

string &idc::trim(string &str, const char c) {
	idc::ltrim(str, c);
	idc::rtrim(str, c);
	return str;
}

char *idc::toUpper(char *str) {
	if (str == nullptr)
		return nullptr;
	int offset = 'A' - 'a';
	char *p = str;
	while (*p != 0) {
		*p += (*p >= 'a' && *p <= 'z') ? offset : 0;
		p++;
	}
	return str;
}

string &idc::toUpper(string &str) {
	int offset = 'A' - 'a';
	for (char &c: str)
		c += (c >= 'a' && c <= 'z') ? offset : 0;
	return str;
}

char *idc::toLower(char *str) {
	if (str == nullptr)
		return nullptr;
	int offset = 'a' - 'A';
	char *p = str;
	while (*p != 0) {
		*p += (*p >= 'A' && *p <= 'Z') ? offset : 0;
		p++;
	}
	return str;
}

string &idc::toLower(string &str) {
	int offset = 'a' - 'A';
	for (char &c: str)
		c += (c >= 'A' && c <= 'Z') ? offset : 0;
	return str;
}