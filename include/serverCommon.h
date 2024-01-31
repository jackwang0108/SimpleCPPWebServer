#pragma once

#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <functional>
#include <iostream>
#include <locale>
#include <string>

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
};// namespace idc