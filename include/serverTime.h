#pragma once

#include <chrono>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std::chrono_literals;
namespace chrono = std::chrono;

namespace idc {

	/**
	 * @brief 将Unix时间time根据格式化字符串fmt格式化后保存到字符串out中
	 * @param time 要转换的Unix时间
	 * @param out 保存结果的字符串
	 * @param fmt 格式化字符串, 默认为"%c", 详细请参考: https://en.cppreference.com/w/cpp/io/manip/put_time
	 * @return 格式化后的字符串
	 */
	std::string &timeToStr(std::time_t time, std::string &out, const std::string &fmt = "%Y-%m-%d %H:%M:%S");

	/**
	 * @brief 将Unix时间time根据格式化字符串fmt格式化后返回
	 * @param time 要转换的Unix时间
	 * @param fmt 格式化字符串, 默认为"%c", 详细请参考: https://en.cppreference.com/w/cpp/io/manip/put_time
	 * @return 格式化后的字符串
	 */
	std::string timeToStr(std::time_t time, const std::string &fmt = "%Y-%m-%d %H:%M:%S");

	/**
	 * @brief 将Unix时间time根据格式化字符串fmt格式化后保存到字符串out中
	 * @param time 要转换的Unix时间
	 * @param out 保存结果的字符串
	 * @param fmt 格式化字符串, 默认为"%c", 详细请参考: https://en.cppreference.com/w/cpp/io/manip/put_time
	 * @return 格式化后的字符串
     * 
     * @note 函数不对out的大小负责, 需要由用户保证out的长度足够
	 */
	char *timeToStr(std::time_t time, char *out, const std::string &fmt = "%Y-%m-%d %H:%M:%S");

	/**
	 * @brief 将chrono中的时间点(time_point)time根据格式化字符串fmt格式化后保存到字符串out中
	 * @tparam Clock 时间点相对的时钟, 默认为system_clock
	 * @tparam Duration 时间点的单位, 默认为seconds
	 * @param time 要转换的Unix时间
	 * @param out 保存结果的字符串
	 * @param fmt 格式化字符串, 默认为"%c", 详细请参考: https://en.cppreference.com/w/cpp/io/manip/put_time
	 * @return 格式化后的字符串
	 */
	template<typename Clock = chrono::system_clock, typename Duration = chrono::seconds>
	std::string &timeToStr(const chrono::time_point<Clock, Duration> time, std::string &out, const std::string &fmt = "%Y-%m-%d %H:%M:%S") {
		std::time_t timeT = chrono::system_clock::to_time_t(time);
		idc::timeToStr(timeT, out, fmt);
		return out;
	}

	/**
	 * @brief 将chrono中的时间点(time_point)time根据格式化字符串fmt格式化后返回
	 * @tparam Clock 时间点相对的时钟, 默认为system_clock
	 * @tparam Duration 时间点的单位, 默认为seconds
	 * @param time 要转换的Unix时间
	 * @param fmt 格式化字符串, 默认为"%c", 详细请参考: https://en.cppreference.com/w/cpp/io/manip/put_time
	 * @return 格式化后的字符串
	 */
	template<typename Clock = chrono::system_clock, typename Duration = chrono::seconds>
	std::string timeToStr(const chrono::time_point<Clock, Duration> time, const std::string &fmt = "%Y-%m-%d %H:%M:%S") {
		std::string result;
		std::time_t timeT = chrono::system_clock::to_time_t(time);
		idc::timeToStr(timeT, result, fmt);
		return result;
	}

	/**
	 * @brief 将chrono中的时间点(time_point)time根据格式化字符串fmt格式化后保存到字符串out中
	 * @tparam Clock 时间点相对的时钟, 默认为system_clock
	 * @tparam Duration 时间点的单位, 默认为seconds
	 * @param time 要转换的Unix时间
	 * @param out 保存结果的字符串
	 * @param fmt 格式化字符串, 默认为"%c", 详细请参考: https://en.cppreference.com/w/cpp/io/manip/put_time
	 * @return 格式化后的字符串
     * 
     * @note 函数不对out的大小负责, 需要由用户保证out的长度足够
	 */
	template<typename Clock = chrono::system_clock, typename Duration = chrono::seconds>
	char *timeToStr(const chrono::time_point<Clock, Duration> time, char *out, const std::string &fmt = "%Y-%m-%d %H:%M:%S") {
		std::time_t timeT = chrono::system_clock::to_time_t(time);
		idc::timeToStr(timeT, out, fmt);
		return out;
	}

	/**
	 * @brief 根据格式字符串fmt解析字符串日期strTime并返回Unix时间
	 * @param strTime 字符串形式的日期
	 * @param fmt 字符串日期的格式
	 * @return 如果失败则返回-1, 否则返回Unix时间
	 */
	std::time_t strToTime(const std::string &strTime, const std::string &fmt = "%Y-%m-%d %H:%M:%S");

	/**
	 * @brief 获得fmt指定格式的系统当前时间并保存到字符串out中
	 * @param out 保存结果的字符串
	 * @param timeInterval 时间偏移量 
	 * @param fmt 格式化字符串, 默认为"%c", 详细请参考: https://en.cppreference.com/w/cpp/io/manip/put_time
	 * @return 格式化后系统当前的时间
	 */
	std::string &getCurrTime(std::string &out, int timeInterval = 0, const std::string &fmt = "%Y-%m-%d %H:%M:%S");

	/**
	 * @brief 获得fmt指定格式的系统当前时间并返回
	 * @param timeInterval 时间偏移量 
	 * @param fmt 格式化字符串, 默认为"%c", 详细请参考: https://en.cppreference.com/w/cpp/io/manip/put_time
	 * @return 格式化后系统当前的时间
	 */
	std::string getCurrTime(int timeInterval = 0, const std::string &fmt = "%Y-%m-%d %H:%M:%S");

	/**
	 * @brief 获得fmt指定格式的系统当前时间并保存到字符串out中
	 * @param out 保存结果的字符串
	 * @param timeInterval 时间偏移量 
	 * @param fmt 格式化字符串, 默认为"%c", 详细请参考: https://en.cppreference.com/w/cpp/io/manip/put_time
	 * @return 格式化后系统当前的时间
     * 
     * @note 函数不对out的大小负责, 需要由用户保证out的长度足够
	 */
	[[maybe_unused]] char *getCurrTime(char *out, int timeInterval = 0, const std::string &fmt = "%Y-%m-%d %H:%M:%S");

	/**
	 * @brief 将fmt格式的字符串时间origin添加偏移量timeInterval后保存到字符串out中
	 * @param origin 原始的日期字符串
	 * @param out 保存结果的字符串
	 * @param timeInterval 时间偏移量, 以秒为单位 
	 * @param fmt 原始字符串的格式
	 * @return 成功为true, 失败为false
	 */
	bool strTimeCalculation(const std::string &origin, std::string &out, int timeInterval = 0, const std::string &fmt = "%Y-%m-%d %H:%M:%S");

	/**
	 * @brief 将fmt格式的字符串时间origin添加偏移量timeInterval后保存到字符串out中
	 * @param origin 原始的日期字符串
	 * @param out 保存结果的字符串
	 * @param timeInterval 时间偏移量, 以秒为单位 
	 * @param fmt 原始字符串的格式
	 * @return 成功为true, 失败为false
     * 
     * @note 函数不对out的大小负责, 需要由用户保证out的长度足够
	 */
	bool strTimeCalculation(const std::string &origin, char *out, int timeInterval = 0, const std::string &fmt = "%Y-%m-%d %H:%M:%S");

	/**
	 * @brief 将fmt格式的字符串时间origin添加偏移量timeInterval后返回
	 * @param origin 原始的日期字符串
	 * @param timeInterval 时间偏移量, 以秒为单位 
	 * @param fmt 原始字符串的格式
	 * @return 成功则返回结果, 失败则返回空字符串
	 */
	std::string strTimeCalculation(const std::string &origin, int timeInterval = 0, const std::string &fmt = "%Y-%m-%d %H:%M:%S");

	/**
	 * @brief 将fmt格式的字符串时间origin添加偏移量timeInterval后保存到字符串out中
	 * @param origin 原始的日期字符串
	 * @tparam Clock 使用的基准时钟, 默认为chrono::system_clock
	 * @tparam Duration 时间偏移量的单位, 默认为chrono::seconds
	 * @param out 保存结果的字符串
	 * @param timeInterval 时间偏移量, chrono中的duration
	 * @param fmt 原始字符串的格式
	 * @return 成功为true, 失败为false
	 */
	template<typename Clock = chrono::system_clock, typename Duration = chrono::seconds>
	bool strTimeCalculation(const std::string &origin, std::string &out, const Duration &timeInterval = Duration(0), const std::string &fmt = "%Y-%m-%d %H:%M:%S") {
		int seconds = (chrono::duration_cast<chrono::seconds>(timeInterval)).count();
		return idc::strTimeCalculation(origin, out, seconds, fmt);
	}

	/**
	 * @brief 将fmt格式的字符串时间origin添加偏移量timeInterval后保存到字符串out中
	 * @param origin 原始的日期字符串
	 * @tparam Clock 使用的基准时钟, 默认为chrono::system_clock
	 * @tparam Duration 时间偏移量的单位, 默认为chrono::seconds
	 * @param out 保存结果的字符串
	 * @param timeInterval 时间偏移量, chrono中的duration
	 * @param fmt 原始字符串的格式
	 * @return 成功为true, 失败为false
	 */
	template<typename Clock = chrono::system_clock, typename Duration = chrono::seconds>
	bool strTimeCalculation(const std::string &origin, char *out, const Duration &timeInterval = Duration(0), const std::string &fmt = "%Y-%m-%d %H:%M:%S") {
		int seconds = (chrono::duration_cast<chrono::seconds>(timeInterval)).count();
		return idc::strTimeCalculation(origin, out, seconds, fmt);
	}

	/**
	 * @brief 将fmt格式的字符串时间origin添加偏移量timeInterval后返回
	 * @param origin 原始的日期字符串
	 * @tparam Clock 使用的基准时钟, 默认为chrono::system_clock
	 * @tparam Duration 时间偏移量的单位, 默认为chrono::seconds
	 * @param timeInterval 时间偏移量, chrono中的duration
	 * @param fmt 原始字符串的格式
	 * @return 成功为true, 失败为false
	 */
	template<typename Clock = chrono::system_clock, typename Duration = chrono::seconds>
	std::string strTimeCalculation(const std::string &origin, const Duration &timeInterval = Duration(0), const std::string &fmt = "%Y-%m-%d %H:%M:%S") {
		int seconds = (chrono::duration_cast<chrono::seconds>(timeInterval)).count();
		return idc::strTimeCalculation(origin, seconds, fmt);
	}

}// namespace idc