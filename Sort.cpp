#include "Sort.h"
#include "Logs.h"

void Sort::addAlgorithm(AdditionalTypes::SortType sortType, AbstractSort* algo)
{
	LOG::INF(std::string{ "Added new algorithm" });
	sortAlgorithms.emplace(std::make_pair( sortType, algo ));
}
AdditionalTypes::Result Sort::sort(const std::string_view& pathToFile, AdditionalTypes::SortType sortType)
{
	auto algo = sortAlgorithms.find(sortType);
	if (algo == sortAlgorithms.end())
	{
		LOG::ERR("Requested algorithm not found");
		return AdditionalTypes::Result::failure;
	}
	LOG::INF(std::string{"Znaleziono algorytm"});
	return sortAlgorithms.at(sortType)->sort(pathToFile);
}