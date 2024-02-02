#pragma once

#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <chrono>
#include <functional>
#include <iomanip>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>
#include <vector>

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

#include "fmt/core.h"
#include "fmt/format.h"

using namespace std::chrono_literals;
namespace chrono = std::chrono;

namespace idc {

	/**
	 * @brief 删除字符串str左侧的字符c
	 * @param str 要删除的字符串
     * @param c 要删除的字符
	 * @return 删除后的字符串
	 */
	char *ltrim(char *str, const char c = ' ');

	/**
	 * @brief 删除字符串str左侧的字符c
	 * @param str 要删除的字符串
     * @param c 要删除的字符
	 * @return 删除后的字符串
	 */
	std::string &ltrim(std::string &str, const char c = ' ');

	/**
	 * @brief 删除字符串str右侧的字符c
	 * @param str 要删除的字符串
	 * @param c 要删除的字符
	 * @return 删除后的字符串
	 */
	char *rtrim(char *str, const char c = ' ');

	/**
	 * @brief 删除字符串str右侧的字符c
	 * @param str 要删除的字符串
	 * @param c 要删除的字符
	 * @return 删除后的字符串
	 */
	std::string &rtrim(std::string &str, const char c = ' ');

	/**
	 * @brief 删除字符串str左右两侧的字符c
	 * @param str 要删除的字符串
	 * @param c 要删除的字符
	 * @return 删除后的字符串
	 */
	char *trim(char *str, const char c = ' ');

	/**
	 * @brief 删除字符串str左右两侧的字符c
	 * @param str 要删除的字符串
	 * @param c 要删除的字符
	 * @return 删除后的字符串
	 */
	std::string &trim(std::string &str, const char c = ' ');

	/**
	 * @brief 删除字符串str左右两侧的字符c
	 * @param str 要删除的字符串
	 * @param c 要删除的字符
	 * @return 删除后的字符串
	 */
	std::string trim(const std::string &str, const char c = ' ');

	/**
	 * @brief 把字符串str中的小写字母转换为大写字母
	 * @param str 要转换的字符串
	 * @return 转换后的字符串
	 */
	char *toUpper(char *str);

	/**
	 * @brief 把字符串str中的小写字母转换为大写字母
	 * @param str 要转换的字符串
	 * @return 转换后的字符串
	 */
	std::string &toUpper(std::string &str);

	/**
	 * @brief 把字符串str中的大写字母转换为小写字母
	 * @param str 要转换的字符串
	 * @return 转换后的字符串
	 */
	char *toLower(char *str);

	/**
	 * @brief 把字符串str中的大写字母转换为小写字母
	 * @param str 要转换的字符串
	 * @return 转换后的字符串
	 */
	std::string &toLower(std::string &str);

	/**
	 * @brief 将字符串str中的子字符串from替换为to
	 * @param str 要替换的字符串
	 * @param from 被替换的子字符串
	 * @param to 替换后的子字符串
	 * @param loopReplace 是否循环替换, 例如: str="Name::::jack", from="::", to=":", 若loopReplace=true, 则替换后得到"Name:jack"
	 * @return 替换成功true, 失败false
     * 
     * @note 如果字符串to包含字符串from, 则直接返回, 例如将"name:Jack"的":"替换为"::", 由于逻辑错误, 因此不会进行任何替换
     * 
     * @warning 若to比from长, 则需要确保str足够大, 但是函数不会检查str是否足够大
	 */
	bool replace(char *str, const std::string &from, const std::string &to, const bool loopReplace = false);


	/**
	 * @brief 将字符串str中的子字符串from替换为to
	 * @param str 要替换的字符串
	 * @param from 被替换的子字符串
	 * @param to 替换后的子字符串
	 * @param loopReplace 是否循环替换, 例如: str="Name::::jack", from="::", to=":", 若loopReplace=true, 则替换后得到"Name:jack"
	 * @return 替换成功true, 失败false
     * 
     * @note 若loopReplace为true, 且字符串to包含字符串from, 则直接返回, 例如将"name:Jack"的":"替换为"::", 由于逻辑错误, 因此不会进行任何替换
	 */
	bool replace(std::string &str, const std::string &from, const std::string &to, const bool loopReplace = false);

	/**
	 * @brief 从字符串src中提取一个数字字符串并存放到dst中
	 * @param src 要提取数字的字符串
	 * @param dst 存放数字的字符串
	 * @param extractSign 是否提取符号
	 * @param extractDot 是否提取小数点
	 * @return 存放数字的字符串
     * 
     * @note src和dst可以相同
     * @note 该函数不会检查数字字符串的合法性, 只是单纯的提取数字字符
	 */
	char *extractNumber(const std::string &src, char *dst, const bool extractSign = false, const bool extractDot = false);

	/**
	 * @brief 从字符串src中提取一个数字字符串并存放到dst中
	 * @param src 要提取数字的字符串
	 * @param dst 存放数字的字符串
	 * @param extractSign 是否提取符号
	 * @param extractDot 是否提取小数点
	 * @return 存放数字的字符串
     * 
     * @note src和dst可以相同
     * @note 该函数不会检查数字字符串的合法性, 只是单纯的提取数字字符
	 */
	std::string &extractNumber(const std::string &src, std::string &dst, const bool extractSign = false, const bool extractDot = false);

	/**
	 * @brief 从字符串src中提取一个数字字符串
	 * @param src 要提取数字的字符串
	 * @param extractSign 是否提取符号
	 * @param extractDot 是否提取小数点
	 * @return 提取得到的数字字符串
     * 
     * @note 该函数不会检查数字字符串的合法性, 只是单纯的提取数字字符
	 */
	std::string extractNumber(const std::string &src, const bool extractSign = false, const bool extractDot = false);

	/**
	 * @brief 检查字符串str是否匹配模式pattern
	 * @param str 待检查的字符串
	 * @param pattern 需要匹配的模式
	 * @return true则匹配成功, false则匹配失败
     * 
     * @note 匹配时忽略大小写
	 */
	bool matchStr(const std::string &str, const std::string &pattern);

	class StrSpliter {
	private:
		std::vector<std::string> words;

		// 禁止拷贝构造函数
		StrSpliter(const StrSpliter &other) = delete;
		// 禁止赋值函数
		StrSpliter &operator=(const StrSpliter &) = delete;

	public:
		/**
		 * @brief 初始化空的StrSpliter对象
		 */
		StrSpliter() : words(0, "") {}

		StrSpliter(StrSpliter &&other);

		/**
		 * @brief 初始化以字符串str中的内容被字符串delim分割后的词组为内容的StrSpliter
		 * @param str 被分割的字符串
		 * @param delim 分隔符
		 * @param trim 是否去掉空白
		 */
		StrSpliter(const std::string &str, const std::string &delim = ",", const bool trim = true);

		/**
		 * @brief 将已经初始化的StrSpliter对象重新初始化为字符串str被字符串delim分割后的词组为内容的StrSpliter
		 * @param str 被分割的字符串
		 * @param delim 分隔符
		 * @param trim 是否去掉空白
		 */
		void resplit(const std::string &str, const std::string &delim = ",", const bool trim = false, const bool clear = true);

		/**
		 * @brief 初始化以字符串str中的内容被字符串delim分割后的词组为内容的StrSpliter
		 * @param str 被分割的字符串
		 * @param delim 分隔符
		 * @param trim 是否去掉空白
		 * @return StrSpliter对象
		 */
		static StrSpliter split(const std::string &str, const std::string &delim, const bool trim = false);


		const std::string &operator[](int idx) const { return words[idx]; }

		/**
		 * @brief 返回分割后的单词数
		 * @return 返回分割后的单词数
		 */
		size_t size() const { return words.size(); }


		/**
		 * @brief 将第idx个字段的值转化为对应类型后保存到变量out中
		 * @tparam T 变量的类型
		 * @param idx 要获得值的字段的idx
		 * @param out 保存值的变量
		 * @return out的引用
		 */
		template<typename T>
		T &getValue(int idx, T &out) const {
			std::istringstream iss;
			if constexpr (std::is_arithmetic_v<T>)
				iss.str(idc::extractNumber(words[idx], true, true));
			else
				iss.str(words[idx]);
			iss >> out;
			return out;
		}

		/**
		 * @brief 获得第idx个字段的值
		 * @tparam T idx字段的类型 
		 * @param idx 要获得值的字段的idx
		 * @return 字段的值
		 */
		template<typename T>
		T getValue(int idx) const {
			T temp;
			getValue(idx, temp);
			return temp;
		}

		/**
		 * @brief 将第idx个字段保存到字符串out中
		 * @param idx 字段的idx
		 * @param out 存储字段的字符串
		 * @param size 保存的长度, -1表示字段的长度
		 * @return out
         * 
         * @note size=-1时需要用户保证out大于字段的长度
		 */
		char *getValue(int idx, char *out, size_t size = -1) const {
			size = size == -1 ? words[idx].length() : size;
			strncpy(out, words[idx].c_str(), size);
			return out;
		}
	};

	std::ostream &operator<<(std::ostream &os, const idc::StrSpliter &ss);

	/**
	 * @brief 获得字符串形式的xml文件中名为fieldName的标签的值, 并将其存储于变量out中
	 * @tparam T 变量out的类型
	 * @param xmlBuf 字符串形式的xml文件
	 * @param fieldName 要提取的标签名
	 * @param out 存储标签值的变量
	 * @return 是否成功
	 */
	template<typename T>
	bool getXmlFieldValue(const std::string &xmlBuf, const std::string fieldName, T &out) {
		std::string startTag = "<" + fieldName + ">";
		std::string endTag = "</" + fieldName + ">";

		int startPos = xmlBuf.find(startTag);
		if (startPos == std::string::npos)
			return false;

		int endPos = xmlBuf.find(endTag);
		if (endPos == std::string::npos)
			return false;

		std::string field = xmlBuf.substr(startPos + startTag.length(), endPos - startPos - startTag.length());

		std::istringstream iss;
		if constexpr (std::is_arithmetic_v<T>)
			iss.str(idc::extractNumber(field, true, true));
		else
			iss.str(field);
		iss >> out;

		return true;
	}

	/**
	 * @brief 获得字符串形式的xml文件中名为fieldName的标签的值并返回
	 * @tparam T 变量out的类型
	 * @param xmlBuf 字符串形式的xml文件
	 * @param fieldName 要提取的标签名
	 * @return first为是否成功, second为获取得到的值
	 */
	template<typename T>
	std::pair<bool, T> getXmlFieldValue(const std::string &xmlBuf, const std::string fieldName) {
		T temp = T();
		bool result = getXmlFieldValue(xmlBuf, fieldName, temp);
		return {result, temp};
	}


	/**
	 * @brief 将Unix时间time根据格式化字符串fmt格式化后保存到字符串out中
	 * @param time 要转换的Unix时间
	 * @param out 保存结果的字符串
	 * @param fmt 格式化字符串, 默认为"%c", 详细请参考: https://en.cppreference.com/w/cpp/io/manip/put_time
	 * @return 格式化后的字符串
	 */
	std::string &timeToStr(const std::time_t time, std::string &out, const std::string &fmt = "%Y-%m-%d %H:%M:%S");

	/**
	 * @brief 将Unix时间time根据格式化字符串fmt格式化后返回
	 * @param time 要转换的Unix时间
	 * @param fmt 格式化字符串, 默认为"%c", 详细请参考: https://en.cppreference.com/w/cpp/io/manip/put_time
	 * @return 格式化后的字符串
	 */
	std::string timeToStr(const std::time_t time, const std::string &fmt = "%Y-%m-%d %H:%M:%S");

	/**
	 * @brief 将Unix时间time根据格式化字符串fmt格式化后保存到字符串out中
	 * @param time 要转换的Unix时间
	 * @param out 保存结果的字符串
	 * @param fmt 格式化字符串, 默认为"%c", 详细请参考: https://en.cppreference.com/w/cpp/io/manip/put_time
	 * @return 格式化后的字符串
     * 
     * @note 函数不对out的大小负责, 需要由用户保证out的长度足够
	 */
	char *timeToStr(const std::time_t time, char *out, const std::string &fmt = "%Y-%m-%d %H:%M:%S");

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
	std::string &getCurrTime(std::string &out, const int timeInterval = 0, const std::string &fmt = "%Y-%m-%d %H:%M:%S");

	/**
	 * @brief 获得fmt指定格式的系统当前时间并返回
	 * @param timeInterval 时间偏移量 
	 * @param fmt 格式化字符串, 默认为"%c", 详细请参考: https://en.cppreference.com/w/cpp/io/manip/put_time
	 * @return 格式化后系统当前的时间
	 */
	std::string getCurrTime(const int timeInterval = 0, const std::string &fmt = "%Y-%m-%d %H:%M:%S");

	/**
	 * @brief 获得fmt指定格式的系统当前时间并保存到字符串out中
	 * @param out 保存结果的字符串
	 * @param timeInterval 时间偏移量 
	 * @param fmt 格式化字符串, 默认为"%c", 详细请参考: https://en.cppreference.com/w/cpp/io/manip/put_time
	 * @return 格式化后系统当前的时间
     * 
     * @note 函数不对out的大小负责, 需要由用户保证out的长度足够
	 */
	char *getCurrTime(char *out, const int timeInterval = 0, const std::string &fmt = "%Y-%m-%d %H:%M:%S");

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
		auto tp = chrono::time_point<Clock>(timeInterval);
		time_t timeIntervalTime = Clock::to_time_t(tp);
		return idc::strTimeCalculation(origin, out, timeIntervalTime, fmt);
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
		auto tp = chrono::time_point<Clock>(timeInterval);
		time_t timeIntervalTime = Clock::to_time_t(tp);
		return idc::strTimeCalculation(origin, out, timeIntervalTime, fmt);
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
};// namespace idc