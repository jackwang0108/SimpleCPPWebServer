#pragma once

#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <functional>
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
		StrSpliter(const std::string &str, const std::string &delim, const bool trim = false);

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

		template<typename T>
		T &getValue(int idx, T &out) const {
			std::istringstream iss(words[idx]);
			iss >> out;
			return out;
		}

		template<typename T>
		T getValue(int idx) const {
			T temp;
			getValue(idx, temp);
			return temp;
		}

		char *getValue(int idx, char *out, size_t size = -1) const {
			size = size == -1 ? words[idx].length() : size;
			strncpy(out, words[idx].c_str(), size);
			return out;
		}
	};

	std::ostream &operator<<(std::ostream &os, const idc::StrSpliter &ss);
};// namespace idc