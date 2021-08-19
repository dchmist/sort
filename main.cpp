#include "Sort/SortManager.h"
#include "Factory/SortFactory.h"
#include "ParseArgs.h"
#include <iostream>

int main(int argc, char** argv)
{
	auto args = parse::parseInputArgs(argc, argv);	

	Factory::SortFactory factory;
	Sort::SortManager sortManager{&factory};
	auto retVal = sortManager.sort(args.input, args.sortType, args.output);
	std::cout << "Sort result : " << static_cast<int>(retVal) << '\n';
	return 1;
}