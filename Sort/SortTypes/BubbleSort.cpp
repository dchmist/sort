#include "Sort/SortTypes/BubbleSort.h"
#include "FileSupport/FileHandler.h"
#include "LOG/Logs.h"
#include <algorithm>

using namespace Sort::SortTypes;

AdditionalTypes::Result BubbleSort::sort(const std::string_view& input, const std::string_view& output)
{
    LOG::INF("BubbleSort started");
    auto buff = FileSupport::FileHandler::getContentOfFile(input);
    if (buff.size() == 0)
    {
        return AdditionalTypes::Result::emptyBuffer;
    }
	bubbleSort(buff);
	return FileSupport::FileHandler::saveData(buff, output) ? AdditionalTypes::Result::success : AdditionalTypes::Result::failure;
}

void BubbleSort::bubbleSort(std::vector<int>& buffer)
{
    for (size_t i = 0; i < buffer.size(); ++i) 
    {
        for (size_t j = 0; j < buffer.size() - 1; ++j) 
        {
            if (buffer.at(j) > buffer.at(j + 1)) 
            {
                std::swap(buffer.at(j), buffer.at(j + 1));
            }
        }
    }
}