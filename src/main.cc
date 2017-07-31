/*
 * @brief Entry point for algorithms application
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <functional>

#include "utils.hh"
#include "sorting.hh"
#include "binarysearching.hh"

int main()
{
    using namespace Algorithms;

    std::cout << "Sandbox for checking various STL algorithms" << std::endl;

    const std::vector<int> testVecInput1 { 1, 3, 2, 8, 3, 6, 8, 1, 4, 9 };
    const std::vector<std::pair<int, char>> testVecInput2 { {1, 'a'}, {3, 'b'}, {2, 'c'}, {8, 'd'},
                                                            {3, 'e'}, {6, 'f'}, {8, 'g'}, {1, 'h'},
                                                            {4, 'i'}, {9, 'j'}};

    // Ordinary sort
    {
        std::cout << std::endl << "sort/is_sorted check" << std::endl;

        auto testVec1(testVecInput1);
        Sorting::doSort(testVec1);

        auto testVec2(testVecInput2);
        Sorting::doSort(testVec2);
    }

    // Stable sort
    {
        std::cout << std::endl << "stable_sort/is_sorted check" << std::endl;

        auto testVec1(testVecInput1);
        Sorting::doStableSort(testVec1);

        auto testVec2(testVecInput2);
        Sorting::doStableSort(testVec2);
    }

    // Partial sort
    {
        std::cout << std::endl << "partial_sort/is_sorted_until check" << std::endl;

        auto testVec1(testVecInput1);
        auto middleIter1 = Utils::getMiddleIterator(testVec1);
        Sorting::doPartialSort(testVec1, middleIter1);

        auto testVec2(testVecInput2);
        auto middleIter2 = Utils::getMiddleIterator(testVec2);
        Sorting::doPartialSort(testVec2, middleIter2);
    }

    // Partial sort copy
    {
        std::cout << std::endl << "partial_sort_copy/is_sorted check" << std::endl;

        auto testVec1(testVecInput1);
        auto middleIter1 = Utils::getMiddleIterator(testVec1);
        Sorting::doPartialSortCopy(testVec1, middleIter1);

        auto testVec2(testVecInput2);
        auto middleIter2 = Utils::getMiddleIterator(testVec2);
        Sorting::doPartialSortCopy(testVec2, middleIter2);
    }

    // Nth element
    {
        std::cout << std::endl << "nth_element" << std::endl;

        auto testVec1(testVecInput1);
        auto middleIter1 = Utils::getMiddleIterator(testVec1);
        Sorting::doNthElement(testVec1, middleIter1);

        auto testVec2(testVecInput2);
        auto middleIter2 = Utils::getMiddleIterator(testVec2);
        Sorting::doNthElement(testVec2, middleIter2);
    }

    // Lower bound
    {
        std::cout << std::endl << "lower_bound check" << std::endl;

        auto testVec1(testVecInput1);
        std::sort(testVec1.begin(), testVec1.end());

        BinarySearching::doLowerBound(testVec1, 4);

        auto testVec2(testVecInput2);
        std::sort(testVec2.begin(), testVec2.end());

        BinarySearching::doLowerBound(testVec2, std::make_pair(3, 'b'));
    }

    // Upper bound
    {
        std::cout << std::endl << "upper_bound check" << std::endl;

        auto testVec1(testVecInput1);
        std::sort(testVec1.begin(), testVec1.end());

        BinarySearching::doUpperBound(testVec1, 4);

        auto testVec2(testVecInput2);
        std::sort(testVec2.begin(), testVec2.end());

        BinarySearching::doUpperBound(testVec2, std::make_pair(3, 'b'));
    }

    // Equal range
    {
        std::cout << std::endl << "equal_range check" << std::endl;

        auto testVec1(testVecInput1);
        std::sort(testVec1.begin(), testVec1.end());

        BinarySearching::doEqualRange(testVec1, 3);

        auto testVec2(testVecInput2);
        std::sort(testVec2.begin(), testVec2.end());

        BinarySearching::doEqualRange(testVec2, std::make_pair(3, 'b'));
    }

    // Binary search
    {
        std::cout << std::endl << "binary_search check" << std::endl;

        auto testVec1(testVecInput1);
        std::sort(testVec1.begin(), testVec1.end());

        BinarySearching::doBinarySearch(testVec1, 3);

        auto testVec2(testVecInput2);
        std::sort(testVec2.begin(), testVec2.end());

        BinarySearching::doBinarySearch(testVec2, std::make_pair(3, 'b'));
    }

    return EXIT_SUCCESS;
}
