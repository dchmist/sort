#include "ParseArgs.h"
#include "cxxopts.hpp"
#include "LOG/Logs.h"
#include "AdditionalTypes.h"

namespace parse{
    void printHelp();
    ParsedArgs parseInputArgs(int argc, char** argv)
    {
        ParsedArgs args;
        std::string sortType;
        cxxopts::Options options("Test", "Let's try this shit");

        options.add_options()
            ("i,input", "Input file name", cxxopts::value<std::string>())
            ("o,output", "Output file name", cxxopts::value<std::string>())
            ("s,sort", "Sort type", cxxopts::value<std::string>())
        ;
        auto result = options.parse(argc, argv);
        if(result.count("i") && result.count("s") && result.count("o"))
        {
            args.input = result["i"].as<std::string>();
            args.output = result["o"].as<std::string>();
            args.sortType = AdditionalTypes::strToSortType.at(result["s"].as<std::string>());
        }
        else
        {
            LOG::ERR("Parse Error. Missing arguments");
        }
        LOG::INF("Parse arguments success.");

        return args;
    }
    void printHelp()
    {
        std::cout << "Instructions:\n"
            << "  -i <path_to_file> \t-path to input file\n" 
            << "  -o <path_to_file> \t-path to output file\n"
            << "  -s \t types of sort(bubbleSort, quickSort)\n";
    }
}