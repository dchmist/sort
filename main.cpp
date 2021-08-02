#include "Sort/SortManager.h"
#include "Factory/SortFactory.h"
#include <iostream>

int main(int argc, char** argv)
{
	std::string_view path{ "/mnt/c/Users/twist/source/test_data/test.txt" };
	std::cout << "Path : " << path << '\n';
	
	Factory::SortFactory factory;
	Sort::SortManager sortManager{&factory};
	auto retVal = sortManager.sort(path, AdditionalTypes::SortType::bubbleSort);
	std::cout << "Sort result : " << static_cast<int>(retVal) << '\n';
	return 1;
}