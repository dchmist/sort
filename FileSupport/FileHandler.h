#pragma once

#include <vector>
#include <string_view>

namespace FileSupport
{
	class FileHandler
	{
	public:
		static std::vector<int> getContentOfFile(const std::string_view& pathToFile);
		static bool saveData(const std::vector<int>& buff, const std::string_view& pathToFile);
	};
}