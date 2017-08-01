#pragma once

#include <algorithm>
#include <cassert>

#include "utils.hh"

namespace Algorithms
{

namespace Sorting
{

template<typename T>
void doSort(T& container)
{
    Utils::printContainer(container, "Input");

    std::sort(container.begin(), container.end());

    Utils::printContainer(container, "Sorted");

    assert(std::is_sorted(container.begin(), container.end()) == true);
}

template<typename T>
void doStableSort(T& container)
{
    Utils::printContainer(container, "Input");

    std::stable_sort(container.begin(), container.end());

    Utils::printContainer(container, "Sorted");

    assert(std::is_sorted(container.begin(), container.end()) == true);

}

template<typename T>
void doPartialSort(T& container, typename T::iterator& middle)
{
    Utils::printContainer(container, "Input");

    std::partial_sort(container.begin(), middle, container.end());

    Utils::printContainer(container, "Sorted");

    assert(std::is_sorted(container.begin(), container.end()) != true);

    auto sortedUntilDist = std::distance(container.begin(),
                                         std::is_sorted_until(container.begin(), container.end()));
    auto middleDist = std::distance(container.begin(), middle);

    assert(sortedUntilDist >= middleDist);
}

template<typename T>
void doPartialSortCopy(T& container, typename T::iterator& middle)
{
    Utils::printContainer(container, "Input");

    T outContainer;

    std::copy(container.begin(), middle, std::back_inserter(outContainer));
    std::partial_sort_copy(container.begin(), container.end(),
                           outContainer.begin(), outContainer.end());

    Utils::printContainer(outContainer, "Sorted");

    assert(std::is_sorted(outContainer.begin(), outContainer.end()) == true);
}


template<typename T>
void doNthElement(T& container, typename T::iterator& middle)
{
    Utils::printContainer(container, "Input");

    std::nth_element(container.begin(), middle, container.end());

    Utils::highlightSingle(container, middle, "Nth");

    assert(std::is_sorted(container.begin(), container.end()) != true);
}

}

}
