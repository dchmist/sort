#include "Sort.h"
#include "BubbleSort.h"
#include <iostream>

int main(int argc, char* argv)
{
	std::string_view path{"C:\\Users\\twist\\source\\test_data\\test.txt"};
	//std::string_view path{ "C:/Users/twist/source/test_data/test.txt" };
	std::cout << "Path : " << path << '\n';
	
	Sort sortowanko;
	SortTypes::BubbleSort bbSort;
	sortowanko.addAlgorithm(AdditionalTypes::SortType::bubbleSort, &bbSort);
	auto retVal = sortowanko.sort(path, AdditionalTypes::SortType::bubbleSort);
	std::cout << "Sort result : " << static_cast<int>(retVal) << '\n';
	return 1;
}