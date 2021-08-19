#pragma once

#include "Abstract/AbstractFactory.h"

namespace Sort {
	class SortManager
	{
	public:
		SortManager(Abstract::AbstractFactory* fac);
		AdditionalTypes::Result sort(const std::string_view& input, AdditionalTypes::SortType sortType, const std::string_view& output);
	private:
		Abstract::AbstractFactory* factory;
	};
}