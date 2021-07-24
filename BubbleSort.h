#pragma once

#include "AbstractSort.h"
#include <vector>

namespace SortTypes {

	class BubbleSort : public AbstractSort
	{
	public:
		AdditionalTypes::Result sort(const std::string_view& filePath) override;
	private:
		void bubbleSort(std::vector<int>& buffer);
		std::string changeFileName(const std::string_view& oldPath);
	};

};