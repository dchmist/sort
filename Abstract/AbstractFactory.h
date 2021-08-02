#pragma once

#include "AbstractSort.h"
#include <memory>

namespace Abstract
{
	class AbstractFactory
	{
	public:
		virtual const std::unique_ptr<Abstract::AbstractSort>& getSortAlgorithm(const AdditionalTypes::SortType) const = 0;
		virtual ~AbstractFactory() = default;
	};
}