/*
 * @brief Entry point for algorithms application
 */
#include <iostream>
#include <vector>
#include <cassert>

#include "utils.hh"
#include "sortingalgorithms.hh"

template <typename T>
void doSort(const T& container);

template <typename T>
void doStableSort(const T& container);

template <typename T>
void doPartialSort(const T& container);

template <typename T>
void doPartialSortCopy(const T& container);

int main()
{
    std::cout << "Sandbox for checking various STL algorithms" << std::endl;

    std::vector<int> testVecInput1 { 1, 3, 2, 8, 3, 6, 8, 1, 4, 9 };
    std::vector<std::pair<int, int>> testVecInput2 { {1, 0}, {3, 1}, {2, 2},
                                                     {8, 3}, {3, 4}, {6, 5},
                                                     {8, 6}, {1, 7}, {4, 8}, {9, 9}};

    // Ordinary sort
    {
        std::cout << std::endl << "Ordinary sorting" << std::endl;

        doSort(testVecInput1);
        doSort(testVecInput2);
    }

    // Stable sort
    {
        std::cout << std::endl << "Stable sorting" << std::endl;

        doStableSort(testVecInput1);
        doStableSort(testVecInput2);
    }

    // Partial sort
    {
        std::cout << std::endl << "Partial sorting" << std::endl;

        doPartialSort(testVecInput1);
        doPartialSort(testVecInput2);
    }

    // Partial sort copy
    {
        std::cout << std::endl << "Partial sorting copy" << std::endl;

        doPartialSortCopy(testVecInput1);
        doPartialSortCopy(testVecInput2);
    }

	return 0;
}

template <typename T>
void doSort(const T& container)
{
    T testContainer;
    std::copy(container.begin(), container.end(), std::back_inserter(testContainer));

    Utils::print(testContainer, "Input");
    SortingAlgorithms::checkSort(testContainer);
    Utils::print(testContainer, "Output");

    assert(std::is_sorted(testContainer.begin(), testContainer.end()) == true);
}

template <typename T>
void doStableSort(const T& container)
{
    T testContainer;
    std::copy(container.begin(), container.end(), std::back_inserter(testContainer));

    Utils::print(testContainer, "Input");
    SortingAlgorithms::checkStableSort(testContainer);
    Utils::print(testContainer, "Output");

    assert(std::is_sorted(testContainer.begin(), testContainer.end()) == true);
}

template <typename T>
void doPartialSort(const T& container)
{
    T testContainer;
    std::copy(container.begin(), container.end(), std::back_inserter(testContainer));

    Utils::print(testContainer, "Input");
    SortingAlgorithms::checkPartialSort(testContainer);
    Utils::print(testContainer, "Output");

    assert(std::is_sorted(testContainer.begin(), testContainer.end()) != true);
}

template <typename T>
void doPartialSortCopy(const T& container)
{
    T testContainer;
    std::copy(container.begin(), container.end(), std::back_inserter(testContainer));

    T outContainer;
    typename T::const_iterator middle = container.begin();
    std::advance(middle, container.size()/2);
    std::copy(container.begin(), middle, std::back_inserter(outContainer));

    Utils::print(testContainer, "Input");
    SortingAlgorithms::checkPartialSortCopy(testContainer, outContainer);
    Utils::print(outContainer, "Output");

    assert(std::is_sorted(outContainer.begin(), outContainer.end()) == true);
}
