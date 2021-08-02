#include "Sort/SortManager.h"
#include "Factory/SortFactory.h"
#include "LOG/Logs.h"
#include <iostream>
#include <map>


const std::map<const std::string, const AdditionalTypes::SortType> strToSortType
{
	{"bubbleSort", AdditionalTypes::SortType::bubbleSort}
};

void printHelp()
{
	std::cout << "Instructions:\n"
		<< "  -f <path_to_file> \t-path to file with numbers to sort\n" 
		<< "  -s <sort_type> \t-choose sort type\n"
		<< "\t supported types of sort(for now): bubbleSort\n";
}

int main(int argc, char** argv)
{
	AdditionalTypes::SortType sortType{ AdditionalTypes::SortType::bubbleSort };
	std::string_view path;
	if (argc < 1)
	{
		LOG::ERR("Too few arguments");
		printHelp();
		return 0;
	}
	else if (argc == 1 && std::string{argv[1]}.compare("-h") == 0)
	{
		LOG::ERR("Too few arguments");
		printHelp();
		return 0;
	}
	else 
	{
		if (std::string{ argv[1] }.compare("-f") == 0)
		{
			path = argv[2];
			sortType = strToSortType.at(argv[4]);
		}
		else if (std::string{ argv[1] }.compare("-s") == 0)
		{
			sortType = strToSortType.at(argv[2]);
			path = argv[4];
		}
	}
	
	std::cout << "Path : " << path << '\n';


	Factory::SortFactory factory;
	Sort::SortManager sortManager{&factory};
	auto retVal = sortManager.sort(path, sortType);
	std::cout << "Sort result : " << static_cast<int>(retVal) << '\n';
	return 1;
}