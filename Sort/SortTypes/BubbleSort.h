#pragma once

#include "Abstract/AbstractSort.h"
#include <vector>

namespace Sort::SortTypes {

	class BubbleSort : public Abstract::AbstractSort
	{
	public:
		AdditionalTypes::Result sort(const std::string_view& input, const std::string_view& output) override;
	private:
		void bubbleSort(std::vector<int>& buffer);
		std::string changeFileName(const std::string_view& oldPath);
	};

};