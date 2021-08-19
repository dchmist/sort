#include "Sort/SortTypes/QuickSort.h"
#include "FileSupport/FileHandler.h"
#include "LOG/Logs.h"
#include <algorithm>

using namespace Sort::SortTypes;

AdditionalTypes::Result QuickSort::sort(const std::string_view& input, const std::string_view& output)
{
    LOG::INF("QuickSortSort started");
    auto buff = FileSupport::FileHandler::getContentOfFile(input);
    if (buff.size() == 0)
    {
        return AdditionalTypes::Result::emptyBuffer;
    }
    quickSort(buff, 0, buff.size()-1);
	return FileSupport::FileHandler::saveData(buff, output) ? AdditionalTypes::Result::success : AdditionalTypes::Result::failure;
}

void QuickSort::quickSort(std::vector<int>& buffer, unsigned int left, unsigned int right)
{
	if (left <= right) 
    {
        return;
    }

    unsigned int i = left - 1;
    unsigned int j = right + 1;
	int pivot = buffer.at((left + right) / 2);

	while (true)
	{
		while (pivot > buffer.at(++i));
		while (pivot < buffer.at(--j));

        if(i < j)
        {
            std::swap(buffer.at(i), buffer.at(j));
        }
        else
        {
            break;
        }
	}

    if (j > left)
    {
        quickSort(buffer, left, j);
    }
    if (i < right)
    {
        quickSort(buffer, i, right);
    }
}