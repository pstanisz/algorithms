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
    Utils::print(container, "Input");

    auto result = std::lower_bound(container.begin(), container.end(), value);

    Utils::print(container, result, "Result");
}

}

}
