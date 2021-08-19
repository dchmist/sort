#include "Sort/SortManager.h"
#include "LOG/Logs.h"

using namespace Sort;

SortManager::SortManager(Abstract::AbstractFactory* fac)
{
	factory = fac;
}

AdditionalTypes::Result SortManager::sort(const std::string_view& input, AdditionalTypes::SortType sortType, const std::string_view& output)
{
	return factory->getSortAlgorithm(sortType)->sort(input, output);
}