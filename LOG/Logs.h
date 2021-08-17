#pragma once

#include <string_view>
#include <iostream>

class LOG
{
public:
	static void INF(const std::string log)
	{
		std::cout << "LOG_INF : " << log << '\n';
	}
	static void ERR(const std::string log)
	{
		std::cout << "LOG_ERR : " << log << '\n';
	}
};