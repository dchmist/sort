#pragma once

#include "../AdditionalTypes.h"
#include <string_view>

namespace Abstract 
{
	class AbstractSort
	{
	public:
		virtual AdditionalTypes::Result sort(const std::string_view& filePath) = 0;
		virtual ~AbstractSort() = default;
	};
}