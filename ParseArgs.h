#pragma once

#include "AdditionalTypes.h"
#include <string>

namespace parse
{
    struct ParsedArgs
    {
        std::string input;
        std::string output;
        AdditionalTypes::SortType sortType;
    };

    ParsedArgs parseInputArgs(int argc, char** argv);
}