#pragma once

#include <algorithm>
#include <cassert>

#include "utils.hh"

namespace Algorithms
{

namespace Merging
{

template<typename T, typename U>
void doMerge(const T& container1, const U& container2)
{
    Utils::printContainer(container1, "Input1");
    Utils::printContainer(container2, "Input2");

    T outContainer;
    std::merge(container1.begin(), container1.end(),
               container2.begin(), container2.end(),
               std::back_inserter(outContainer));

    Utils::printContainer(outContainer, "Output");
}

template<typename T>
void doInplaceMerge(T& container, typename T::iterator& middle)
{
    Utils::highlightSingle(container, middle, "Input");

    std::inplace_merge(container.begin(), middle, container.end());

    Utils::printContainer(container, "Output");
}

}

}
