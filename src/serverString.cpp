#include <regex>

#include "serverCommon.h"

using std::cout;
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

string idc::trim(const string &str, const char c) {
	string copy = str;
	idc::ltrim(copy, c);
	idc::rtrim(copy, c);
	return copy;
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

bool idc::replace(char *str, const std::string &from, const std::string &to, const bool loopReplace) {
	if (str == nullptr)
		return false;
	string temp(str);
	if (!idc::replace(temp, from, to, loopReplace))
		return false;

	temp.copy(str, temp.size(), 0);
	str[temp.length()] = 0;
	return true;
}

bool idc::replace(string &str, const std::string &from, const string &to, const bool loopReplace) {
	if (str.length() == 0)
		return false;

	// to包含from
	if (loopReplace && to.find(from) != string::npos)
		return false;

	// 替换
	int curr = 0, last = 0;
	while (curr < str.length()) {
		curr = loopReplace ? str.find(from) : str.find(from, last);
		if (curr == string::npos)
			break;
		str.replace(curr, from.length(), to);
		last = curr + to.length();
	}
	return true;
}


char *idc::extractNumber(const std::string &src, char *dst, const bool extractSign, const bool extractDot) {
	if (dst == nullptr)
		return nullptr;

	string temp = idc::extractNumber(src, extractSign, extractDot);
	temp.copy(dst, temp.length(), 0);
	dst[temp.length()] = 0;
	return dst;
}


std::string &idc::extractNumber(const std::string &src, std::string &dst, const bool extractSign, const bool extractDot) {
	string str;
	for (char c: src) {
		if (extractSign && (c == '-' || c == '+'))
			str.append(1, c);
		else if (extractDot && c == '.')
			str.append(1, c);
		else if (isdigit(c))
			str.append(1, c);
	}
	dst = str;
	return dst;
}

string idc::extractNumber(const string &src, const bool extractSign, const bool extractDot) {
	string dst;
	idc::extractNumber(src, dst, extractSign, extractDot);
	return dst;
}


bool idc::matchStr(const string &str, const string &pattern) {
	std::smatch matches;
	std::regex pat(pattern, std::regex::icase);
	return std::regex_search(str, matches, pat);
}

idc::StrSpliter::StrSpliter(idc::StrSpliter &&other) {
	words = std::move(other.words);
	other.words.clear();
}

idc::StrSpliter::StrSpliter(const string &str, const string &delim, const bool trim) : words(0, "") {
	string token;
	size_t currStart = 0, currEnd = 0, delimLen = delim.length();

	while ((currEnd = str.find(delim, currStart)) != string::npos) {
		token = str.substr(currStart, currEnd - currStart);
		currStart = currEnd + delimLen;
		if (trim)
			words.push_back(idc::trim(token));
		else
			words.push_back(token);
	}
	if (trim)
		words.push_back(idc::trim(str.substr(currStart)));
	else
		words.push_back(str.substr(currStart));
}

idc::StrSpliter idc::StrSpliter::split(const string &str, const string &delim, const bool trim) {
	return std::move(idc::StrSpliter(str, delim, trim));
}

std::ostream &idc::operator<<(std::ostream &os, const idc::StrSpliter &ss) {
	os << "{ ";
	for (int i = 0; i < ss.size(); i++)
		os << ss[i] << (i == ss.size() - 1 ? " " : ", ");
	os << "}";
	return os;
}