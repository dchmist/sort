#pragma once

#include "../Abstract/AbstractFactory.h"

namespace Sort {
	class SortManager
	{
	public:
		SortManager(Abstract::AbstractFactory* fac);
		AdditionalTypes::Result sort(const std::string_view& pathToFile, AdditionalTypes::SortType sortType);
	private:
		Abstract::AbstractFactory* factory;
	};
}