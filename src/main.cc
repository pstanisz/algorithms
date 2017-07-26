/*
 * @brief Entry point for algorithms application
 */
#include <iostream>
#include <vector>
#include <cstdlib>

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

template <typename T>
void doNthElement(const T& container);

int main()
{
    std::cout << "Sandbox for checking various STL algorithms" << std::endl;

    const std::vector<int> testVecInput1 { 1, 3, 2, 8, 3, 6, 8, 1, 4, 9 };
    const std::vector<std::pair<int, char>> testVecInput2 { {1, 'a'}, {3, 'b'}, {2, 'c'}, {8, 'd'},
                                                            {3, 'e'}, {6, 'f'}, {8, 'g'}, {1, 'h'},
                                                            {4, 'i'}, {9, 'j'}};

    // Ordinary sort
    {
        std::cout << std::endl << "sort/is_sorted check" << std::endl;

        doSort(testVecInput1);
        doSort(testVecInput2);
    }

    // Stable sort
    {
        std::cout << std::endl << "stable_sort/is_sorted check" << std::endl;

        doStableSort(testVecInput1);
        doStableSort(testVecInput2);
    }

    // Partial sort
    {
        std::cout << std::endl << "partial_sort/is_sorted_until check" << std::endl;

        doPartialSort(testVecInput1);
        doPartialSort(testVecInput2);
    }

    // Partial sort copy
    {
        std::cout << std::endl << "partial_sort_copy/is_sorted check" << std::endl;

        doPartialSortCopy(testVecInput1);
        doPartialSortCopy(testVecInput2);
    }

    // Nth element
    {
        std::cout << std::endl << "nth_element" << std::endl;

        doNthElement(testVecInput1);
        doNthElement(testVecInput2);
    }

    return EXIT_SUCCESS;
}

template <typename T>
void doSort(const T& container)
{
    T testContainer;
    std::copy(container.begin(), container.end(), std::back_inserter(testContainer));

    SortingAlgorithms::checkSort(testContainer);
}

template <typename T>
void doStableSort(const T& container)
{
    T testContainer;
    std::copy(container.begin(), container.end(), std::back_inserter(testContainer));

    SortingAlgorithms::checkStableSort(testContainer);
}

template <typename T>
void doPartialSort(const T& container)
{
    T testContainer;
    std::copy(container.begin(), container.end(), std::back_inserter(testContainer));

    SortingAlgorithms::checkPartialSort(testContainer);
}

template <typename T>
void doPartialSortCopy(const T& container)
{
    T testContainer;
    std::copy(container.begin(), container.end(), std::back_inserter(testContainer));

    SortingAlgorithms::checkPartialSortCopy(testContainer);
}

template <typename T>
void doNthElement(const T& container)
{
    T testContainer;
    std::copy(container.begin(), container.end(), std::back_inserter(testContainer));

    SortingAlgorithms::checkNthElement(testContainer);
}
