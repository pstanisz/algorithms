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

}
