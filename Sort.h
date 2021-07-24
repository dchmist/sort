#pragma once

#include "AbstractSort.h"
#include <memory>
#include <map>

class Sort
{
public:
	void addAlgorithm(AdditionalTypes::SortType sortType, AbstractSort* algo);
	AdditionalTypes::Result sort(const std::string_view& pathToFile, AdditionalTypes::SortType sortType);
private:
	std::map<AdditionalTypes::SortType, AbstractSort*> sortAlgorithms;
};