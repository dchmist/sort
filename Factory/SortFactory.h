#pragma once

#include "../Abstract/AbstractFactory.h"
#include <memory>
#include <map>

namespace Factory 
{
	class SortFactory : public Abstract::AbstractFactory
	{
	public:
		SortFactory();
		const std::unique_ptr<Abstract::AbstractSort>& getSortAlgorithm(const AdditionalTypes::SortType algoType) const override;
	private:
		std::map<AdditionalTypes::SortType, std::unique_ptr<Abstract::AbstractSort>> sorts;
	};
}