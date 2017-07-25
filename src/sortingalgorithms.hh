#pragma once

#include <algorithm>

namespace SortingAlgorithms
{

template<typename T>
void checkSort(T& container)
{
    std::sort(container.begin(), container.end());
}

template<typename T>
void checkStableSort(T& container)
{
    std::stable_sort(container.begin(), container.end());
}

template<typename T>
void checkPartialSort(T& container)
{
    typename T::iterator middle = container.begin();
    std::advance(middle, container.size()/2);
    std::partial_sort(container.begin(), middle, container.end());
}

template<typename T>
void checkPartialSortCopy(T& container, T& outContainer)
{
    std::partial_sort_copy(container.begin(), container.end(),
                           outContainer.begin(), outContainer.end());
}

}
