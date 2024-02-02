#pragma once

#include <cstring>

#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

// #include "fmt/core.h"
// #include "fmt/format.h"


namespace idc {
	/**
	 * @brief 删除字符串str左侧的字符c
	 * @param str 要删除的字符串
     * @param c 要删除的字符
	 * @return 删除后的字符串
	 */
	char *ltrim(char *str, char c = ' ');

	/**
	 * @brief 删除字符串str左侧的字符c
	 * @param str 要删除的字符串
     * @param c 要删除的字符
	 * @return 删除后的字符串
	 */
	std::string &ltrim(std::string &str, char c = ' ');

	/**
	 * @brief 删除字符串str右侧的字符c
	 * @param str 要删除的字符串
	 * @param c 要删除的字符
	 * @return 删除后的字符串
	 */
	char *rtrim(char *str, char c = ' ');

	/**
	 * @brief 删除字符串str右侧的字符c
	 * @param str 要删除的字符串
	 * @param c 要删除的字符
	 * @return 删除后的字符串
	 */
	std::string &rtrim(std::string &str, char c = ' ');

	/**
	 * @brief 删除字符串str左右两侧的字符c
	 * @param str 要删除的字符串
	 * @param c 要删除的字符
	 * @return 删除后的字符串
	 */
	char *trim(char *str, char c = ' ');

	/**
	 * @brief 删除字符串str左右两侧的字符c
	 * @param str 要删除的字符串
	 * @param c 要删除的字符
	 * @return 删除后的字符串
	 */
	std::string &trim(std::string &str, char c = ' ');

	/**
	 * @brief 删除字符串str左右两侧的字符c
	 * @param str 要删除的字符串
	 * @param c 要删除的字符
	 * @return 删除后的字符串
	 */
	std::string trim(const std::string &str, char c = ' ');

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
	bool replace(char *str, const std::string &from, const std::string &to, bool loopReplace = false);


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
	bool replace(std::string &str, const std::string &from, const std::string &to, bool loopReplace = false);

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
	char *extractNumber(const std::string &src, char *dst, bool extractSign = false, bool extractDot = false);

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
	std::string &extractNumber(const std::string &src, std::string &dst, bool extractSign = false, bool extractDot = false);

	/**
	 * @brief 从字符串src中提取一个数字字符串
	 * @param src 要提取数字的字符串
	 * @param extractSign 是否提取符号
	 * @param extractDot 是否提取小数点
	 * @return 提取得到的数字字符串
     * 
     * @note 该函数不会检查数字字符串的合法性, 只是单纯的提取数字字符
	 */
	std::string extractNumber(const std::string &src, bool extractSign = false, bool extractDot = false);

	/**
	 * @brief 检查字符串str是否匹配模式pattern
	 * @param str 待检查的字符串
	 * @param pattern 需要匹配的模式
	 * @return true则匹配成功, false则匹配失败
     * 
     * @note 匹配时忽略大小写
	 */
	bool matchStr(const std::string &str, const std::string &pattern);

	class StrSplitter {
	private:
		std::vector<std::string> words;


	public:
		// 禁止拷贝构造函数
		StrSplitter(const StrSplitter &other) = delete;
		// 禁止赋值函数
		StrSplitter &operator=(const StrSplitter &) = delete;
		/**
		 * @brief 初始化空的StrSplitter对象
		 */
		StrSplitter() : words(0, "") {}

		StrSplitter(StrSplitter &&other) noexcept ;

		/**
		 * @brief 初始化以字符串str中的内容被字符串delim分割后的词组为内容的StrSplitter
		 * @param str 被分割的字符串
		 * @param delim 分隔符
		 * @param trim 是否去掉空白
		 */
		explicit StrSplitter(const std::string &str, const std::string &delim = ",", bool trim = true);

		/**
		 * @brief 将已经初始化的StrSplitter对象重新初始化为字符串str被字符串delim分割后的词组为内容的StrSplitter
		 * @param str 被分割的字符串
		 * @param delim 分隔符
		 * @param trim 是否去掉空白
		 */
		void resplit(const std::string &str, const std::string &delim = ",", bool trim = false, bool clear = true);

		/**
		 * @brief 初始化以字符串str中的内容被字符串delim分割后的词组为内容的StrSplitter
		 * @param str 被分割的字符串
		 * @param delim 分隔符
		 * @param trim 是否去掉空白
		 * @return StrSplitter对象
		 */
		[[maybe_unused]] static StrSplitter split(const std::string &str, const std::string &delim, bool trim = false);


		const std::string &operator[](int idx) const { return words[idx]; }

		/**
		 * @brief 返回分割后的单词数
		 * @return 返回分割后的单词数
		 */
		[[nodiscard]] size_t size() const { return words.size(); }


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

	std::ostream &operator<<(std::ostream &os, const idc::StrSplitter &ss);

	/**
	 * @brief 获得字符串形式的xml文件中名为fieldName的标签的值, 并将其存储于变量out中
	 * @tparam T 变量out的类型
	 * @param xmlBuf 字符串形式的xml文件
	 * @param fieldName 要提取的标签名
	 * @param out 存储标签值的变量
	 * @return 是否成功
	 */
	template<typename T>
	bool getXmlFieldValue(const std::string &xmlBuf, const std::string &fieldName, T &out) {
		std::string startTag = "<" + fieldName + ">";
		std::string endTag = "</" + fieldName + ">";

		size_t startPos = xmlBuf.find(startTag);
		if (startPos == std::string::npos)
			return false;

		size_t endPos = xmlBuf.find(endTag);
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
}// namespace idc