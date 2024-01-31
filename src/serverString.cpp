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