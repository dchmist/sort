#include "SortFactory.h"
#include "Sort/SortTypes/BubbleSort.h"

using namespace Factory;
SortFactory::SortFactory()
{
	sorts.emplace( std::make_pair(AdditionalTypes::SortType::bubbleSort, std::make_unique<Sort::SortTypes::BubbleSort>()));
}

const std::unique_ptr<Abstract::AbstractSort>& SortFactory::getSortAlgorithm(const AdditionalTypes::SortType algoType) const
{
	return sorts.at(algoType);
}