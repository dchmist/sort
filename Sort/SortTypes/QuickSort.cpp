#include "Sort/SortTypes/QuickSort.h"
#include "FileSupport/FileHandler.h"
#include "LOG/Logs.h"
#include <algorithm>

using namespace Sort::SortTypes;

AdditionalTypes::Result QuickSort::sort(const std::string_view& filePath)
{
    LOG::INF("QuickSortSort started");
    auto buff = FileSupport::FileHandler::getContentOfFile(filePath);
    if (buff.size() == 0)
    {
        return AdditionalTypes::Result::emptyBuffer;
    }
    quickSort(buff, 0, buff.size()-1);
	return FileSupport::FileHandler::saveData(buff, changeFileName(filePath)) ? AdditionalTypes::Result::success : AdditionalTypes::Result::failure;
}

void QuickSort::quickSort(std::vector<int>& buffer, unsigned int left, unsigned int right)
{
	if (left <= right) return;

    int i = left - 1;
    int j = right + 1,
	pivot = buffer.at((left + right) / 2);

	while (true)
	{
		while (pivot > buffer.at(++i));
		while (pivot < buffer.at(--j));

        i < j ? std::swap(buffer.at(i), buffer.at(j)) : break;
	}

    if (j > left)
    {
        quick_sort(buffer, left, j);
    }
    if (i < right)
    {
        quick_sort(buffer, i, right);
    }
}

std::string QuickSort::changeFileName(const std::string_view& oldPath)
{
    auto slashPos = std::find(oldPath.rbegin(), oldPath.rend(), '/');
    if(slashPos == oldPath.rend())
        slashPos = std::find(oldPath.rbegin(), oldPath.rend(), '\\');

    if (slashPos != oldPath.rend())
    {
        std::string removedNameOfFile{ slashPos, oldPath.rend() };
        std::reverse(removedNameOfFile.begin(), removedNameOfFile.end());
        removedNameOfFile += "BubbleSortResult.txt";
        LOG::INF(std::string{ "Changed name to " + removedNameOfFile });
        return removedNameOfFile;
    }
    else {
        using namespace std::string_literals;
        LOG::ERR(std::string{ "There is no \'\\' or / inside of "s + std::string{oldPath} });
    }
    return {};
}