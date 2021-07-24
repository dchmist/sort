#include "BubbleSort.h"
#include "../../FileSupport/FileHandler.h"
#include "../../LOG/Logs.h"
#include <algorithm>

using namespace SortTypes;
AdditionalTypes::Result BubbleSort::sort(const std::string_view& filePath)
{
    LOG::INF("BubbleSort started");
    auto buff = FileSupport::FileHandler::getContentOfFile(filePath);
    if (buff.size() == 0)
    {
        return AdditionalTypes::Result::emptyBuffer;
    }
	bubbleSort(buff);
	return FileSupport::FileHandler::saveData(buff, changeFileName(filePath)) ? AdditionalTypes::Result::success : AdditionalTypes::Result::failure;
}
void BubbleSort::bubbleSort(std::vector<int>& buffer)
{
    for (size_t i = 0; i < buffer.size(); ++i) {
        for (size_t j = 0; j < buffer.size() - 1; ++j) {
            if (buffer.at(j) > buffer.at(j + 1)) {
                std::swap(buffer.at(j), buffer.at(j + 1));
            }
        }
    }
}
std::string BubbleSort::changeFileName(const std::string_view& oldPath)
{
    auto slashPos = std::find(oldPath.rbegin(), oldPath.rend(), '\\');
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
        LOG::ERR(std::string{ "There is no \'\\' inside of "s + std::string{oldPath} });
    }
    return {};
}