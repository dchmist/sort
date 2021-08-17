#include "Sort/SortManager.h"
#include "LOG/Logs.h"

using namespace Sort;

SortManager::SortManager(Abstract::AbstractFactory* fac)
{
	factory = fac;
}

AdditionalTypes::Result SortManager::sort(const std::string_view& pathToFile, AdditionalTypes::SortType sortType)
{
	return factory->getSortAlgorithm(sortType)->sort(pathToFile);
}