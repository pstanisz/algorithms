#pragma once

#include <algorithm>
#include <cassert>

#include "utils.hh"

namespace Algorithms
{

namespace BinarySearching
{

template<typename T>
void doLowerBound(T& container, typename T::value_type value)
{
    Utils::printContainer(container, "Input");

    auto result = std::lower_bound(container.begin(), container.end(), value);

    Utils::highlightSingle(container, result, "Lower");
}

template<typename T>
void doUpperBound(T& container, typename T::value_type value)
{
    Utils::printContainer(container, "Input");

    auto result = std::upper_bound(container.begin(), container.end(), value);

    Utils::highlightSingle(container, result, "Upper");
}

template<typename T>
void doEqualRange(T& container, typename T::value_type value)
{
    Utils::printContainer(container, "Input");

    auto result = std::equal_range(container.begin(), container.end(), value);

    Utils::highlightRange(container, result.first, result.second, "Equal");
}

template<typename T>
void doBinarySearch(T& container, const typename T::value_type& value)
{
    Utils::printContainer(container, "Input");

    auto result = std::binary_search(container.begin(), container.end(), value);

    Utils::printResult(result, "Search");
}

}

}
