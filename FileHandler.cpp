#include "FileHandler.h"
#include "Logs.h"
#include <fstream>
#include <string>

using namespace FileSupport;

std::vector<int> FileHandler::getContentOfFile(const std::string_view& pathToFile)
{
	std::ifstream file;
	file.open(std::string{ pathToFile });
	if (file.is_open())
	{
		std::vector<int> buff;
		int temp;
		while (file >> temp)
		{
			buff.push_back(temp);
		}
		file.close();
		LOG::INF(std::string{ std::string{ "Read the file " + std::string{ pathToFile } + ", inside " + std::to_string(buff.size()) + " numbers" } });
		return std::move(buff);
	}
	LOG::ERR(std::string{ "Read file command failed " + std::string{ pathToFile } });
	return {};
}
bool FileHandler::saveData(const std::vector<int>& buff, const std::string_view& pathToFile)
{
	std::ofstream file;
	file.open(std::string{ pathToFile });
	if (file.is_open())
	{
		for (const auto val : buff)
		{
			file << val << ' ';
		}
		file.close();
		LOG::INF(std::string{ "Saved to file " + std::string{ pathToFile } + " " +std::to_string(buff.size()) + " numbers" });
		return true;
	}
	LOG::ERR(std::string{ "Write file command failed " + std::string{ pathToFile } });
	return false;
}