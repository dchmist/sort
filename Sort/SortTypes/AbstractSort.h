#pragma once

#include <string_view>
#include "../../AdditionalTypes.h"

class AbstractSort
{
public:
	virtual AdditionalTypes::Result sort(const std::string_view& filePath) {
		return AdditionalTypes::Result::calledAbstractClassMethod;
	};
};