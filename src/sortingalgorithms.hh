#pragma once

#include <algorithm>
#include <cassert>

#include "utils.hh"

namespace SortingAlgorithms
{

template<typename T>
void checkSort(T& container)
{
    Utils::print(container, "Input");

    std::sort(container.begin(), container.end());

    Utils::print(container, "Output");

    assert(std::is_sorted(container.begin(), container.end()) == true);
}

template<typename T>
void checkStableSort(T& container)
{
    Utils::print(container, "Input");

    std::stable_sort(container.begin(), container.end());

    Utils::print(container, "Output");

    assert(std::is_sorted(container.begin(), container.end()) == true);

}

template<typename T>
void checkPartialSort(T& container)
{
    Utils::print(container, "Input");

    typename T::iterator middle = container.begin();
    std::advance(middle, container.size()/2);
    std::partial_sort(container.begin(), middle, container.end());

    Utils::print(container, "Output");

    assert(std::is_sorted(container.begin(), container.end()) != true);

    auto sortedUntilDist = std::distance(container.begin(),
                                         std::is_sorted_until(container.begin(), container.end()));
    auto middleDist = std::distance(container.begin(), middle);

    assert(sortedUntilDist >= middleDist);
}

template<typename T>
void checkPartialSortCopy(T& container)
{
    Utils::print(container, "Input");

    T outContainer;
    typename T::iterator middle = container.begin();
    std::advance(middle, container.size()/2);
    std::copy(container.begin(), middle, std::back_inserter(outContainer));
    std::partial_sort_copy(container.begin(), container.end(),
                           outContainer.begin(), outContainer.end());

    Utils::print(outContainer, "Output");

    assert(std::is_sorted(outContainer.begin(), outContainer.end()) == true);
}


template<typename T>
void checkNthElement(T& container)
{
    Utils::print(container, "Input");

    typename T::iterator middle = container.begin();
    std::advance(middle, container.size()/2);
    std::nth_element(container.begin(), middle, container.end());

    Utils::print(container, "Output");

    assert(std::is_sorted(container.begin(), container.end()) != true);
}

}
