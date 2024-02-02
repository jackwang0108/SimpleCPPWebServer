#include "serverCommon.h"

using std::string;
using std::time_t;


string &idc::timeToStr(const time_t time, string &out, const string &fmt) {
	tm timeTm;
	localtime_r(&time, &timeTm);
	std::stringstream ss;
	ss << std::put_time(&timeTm, fmt.c_str());
	out = ss.str();
	return out;
}

string idc::timeToStr(const time_t time, const string &fmt) {
	string result;
	idc::timeToStr(time, result, fmt);
	return result;
}

char *idc::timeToStr(const time_t time, char *out, const string &fmt) {
	if (out == nullptr)
		return nullptr;
	string result;
	idc::timeToStr(time, result, fmt);
	result.copy(out, result.length(), 0);
	return out;
}

time_t idc::strToTime(const string &strTime, const std::string &fmt) {
	// 这里一定要0初始化, 否则mktime可能会因为未填的遗留字段导致返回-1
	tm t{};
	std::istringstream iss(strTime);
	iss >> std::get_time(&t, fmt.c_str());
	if (iss.fail())
		return -1;
	return std::mktime(&t);
}

string &idc::getCurrTime(string &out, const int timeInterval, const string &fmt) {
	time_t now = std::time(nullptr) + timeInterval;
	idc::timeToStr(now, out, fmt);
	return out;
}

string idc::getCurrTime(const int timeInterval, const string &fmt) {
	time_t now = std::time(nullptr) + timeInterval;
	return idc::timeToStr(now, fmt);
}

char *idc::getCurrTime(char *out, const int timeInterval, const string &fmt) {
	time_t now = std::time(nullptr) + timeInterval;
	idc::timeToStr(now, out, fmt);
	return out;
}

bool idc::strTimeCalculation(const string &origin, string &out, int timeInterval, const string &fmt) {
	time_t originTime = idc::strToTime(origin, fmt);
	if (originTime == -1)
		return false;
	time_t outTime = originTime + timeInterval;
	idc::timeToStr(outTime, out, fmt);
	return true;
}

bool idc::strTimeCalculation(const string &origin, char *out, int timeInterval, const string &fmt) {
	time_t originTime = idc::strToTime(origin, fmt);
	if (originTime == -1)
		return false;
	time_t outTime = originTime + timeInterval;
	idc::timeToStr(outTime, out, fmt);
	return true;
}

string idc::strTimeCalculation(const string &origin, int timeInterval, const string &fmt) {
	time_t originTime = idc::strToTime(origin, fmt);
	if (originTime == -1)
		return "";
	time_t outTime = originTime + timeInterval;
	return idc::timeToStr(outTime, fmt);
}
