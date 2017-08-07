#pragma once

#include <algorithm>
#include <cassert>

#include "utils.hh"

namespace Algorithms
{

namespace Set
{

template<typename T>
void doIncludes(const T& container1, const T& container2)
{
    Utils::printContainer(container1, "Input1");
    Utils::printContainer(container2, "Input2");

    auto result = std::includes(container1.begin(), container1.end(),
                                container2.begin(), container2.end());

    Utils::printResult(result, "Input1 includes input2");
}

}

}
