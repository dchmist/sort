#pragma once
#include <unordered_map>
#include <string>
namespace AdditionalTypes
{
	enum class Result
	{
		failure,
		success,
		calledAbstractClassMethod,
		emptyBuffer
	};
	
	enum class SortType
	{
		bubbleSort,
		quickSort
	};
	const std::unordered_map<std::string, SortType> strToSortType
	{
		{"bubbleSort", SortType::bubbleSort},
		{"quickSort", SortType::quickSort}
	};
}