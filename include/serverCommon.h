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

};// namespace idc