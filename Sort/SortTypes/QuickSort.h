#pragma once

#include "Abstract/AbstractSort.h"
#include <vector>

namespace Sort::SortTypes {

	class QuickSort : public Abstract::AbstractSort
	{
	public:
		AdditionalTypes::Result sort(const std::string_view& input, const std::string_view& output) override;
	private:
		void quickSort(std::vector<int>& buffer, unsigned int left, unsigned int right);
		std::string changeFileName(const std::string_view& oldPath);
	};

};