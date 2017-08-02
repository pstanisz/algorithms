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
#include "merging.hh"

int main()
{
    using namespace Algorithms;

    std::cout << "Sandbox for checking various STL algorithms" << std::endl;

    const std::vector<int> testVecInput1 { 1, 3, 2, 8, 3, 6, 8, 1, 4, 9 };
    const std::vector<int> testVecInput2 { 3, 6, 9, 1, 2, 8, 3 };

    const std::vector<std::pair<int, char>> testVecInput3 { {3, 'a'}, {1, 'b'}, {2, 'c'}, {9, 'd'},
                                                            {7, 'e'}, {4, 'f'}, {3, 'g'}, {4, 'h'},
                                                            {8, 'i'}, {7, 'j'}};
    const std::vector<std::pair<int, char>> testVecInput4 { {3, 'k'}, {7, 'l'}};

    // Ordinary sort
    {
        std::cout << std::endl << "sort/is_sorted check" << std::endl;

        auto testVec1(testVecInput1);
        Sorting::doSort(testVec1);

        auto testVec3(testVecInput3);
        Sorting::doSort(testVec3);
    }

    // Stable sort
    {
        std::cout << std::endl << "stable_sort/is_sorted check" << std::endl;

        auto testVec1(testVecInput1);
        Sorting::doStableSort(testVec1);

        auto testVec3(testVecInput3);
        Sorting::doStableSort(testVec3);
    }

    // Partial sort
    {
        std::cout << std::endl << "partial_sort/is_sorted_until check" << std::endl;

        auto testVec1(testVecInput1);
        auto middleIter1 = Utils::getMiddleIterator(testVec1);
        Sorting::doPartialSort(testVec1, middleIter1);

        auto testVec3(testVecInput3);
        auto middleIter2 = Utils::getMiddleIterator(testVec3);
        Sorting::doPartialSort(testVec3, middleIter2);
    }

    // Partial sort copy
    {
        std::cout << std::endl << "partial_sort_copy/is_sorted check" << std::endl;

        auto testVec1(testVecInput1);
        auto middleIter1 = Utils::getMiddleIterator(testVec1);
        Sorting::doPartialSortCopy(testVec1, middleIter1);

        auto testVec3(testVecInput3);
        auto middleIter2 = Utils::getMiddleIterator(testVec3);
        Sorting::doPartialSortCopy(testVec3, middleIter2);
    }

    // Nth element
    {
        std::cout << std::endl << "nth_element" << std::endl;

        auto testVec1(testVecInput1);
        auto middleIter1 = Utils::getMiddleIterator(testVec1);
        Sorting::doNthElement(testVec1, middleIter1);

        auto testVec3(testVecInput3);
        auto middleIter2 = Utils::getMiddleIterator(testVec3);
        Sorting::doNthElement(testVec3, middleIter2);
    }

    // Lower bound
    {
        std::cout << std::endl << "lower_bound check" << std::endl;

        auto testVec1(testVecInput1);
        std::sort(testVec1.begin(), testVec1.end());

        BinarySearching::doLowerBound(testVec1, 4);

        auto testVec3(testVecInput3);
        std::sort(testVec3.begin(), testVec3.end());

        BinarySearching::doLowerBound(testVec3, std::make_pair(3, 'b'));
    }

    // Upper bound
    {
        std::cout << std::endl << "upper_bound check" << std::endl;

        auto testVec1(testVecInput1);
        std::sort(testVec1.begin(), testVec1.end());

        BinarySearching::doUpperBound(testVec1, 4);

        auto testVec3(testVecInput3);
        std::sort(testVec3.begin(), testVec3.end());

        BinarySearching::doUpperBound(testVec3, std::make_pair(3, 'b'));
    }

    // Equal range
    {
        std::cout << std::endl << "equal_range check" << std::endl;

        auto testVec1(testVecInput1);
        std::sort(testVec1.begin(), testVec1.end());

        BinarySearching::doEqualRange(testVec1, 3);

        auto testVec3(testVecInput3);
        std::sort(testVec3.begin(), testVec3.end());

        BinarySearching::doEqualRange(testVec3, std::make_pair(3, 'g'));
    }

    // Binary search
    {
        std::cout << std::endl << "binary_search check" << std::endl;

        auto testVec1(testVecInput1);
        std::sort(testVec1.begin(), testVec1.end());

        BinarySearching::doBinarySearch(testVec1, 3);

        auto testVec3(testVecInput3);
        std::sort(testVec3.begin(), testVec3.end());

        BinarySearching::doBinarySearch(testVec3, std::make_pair(3, 'b'));
    }

    // Merge
    {
        std::cout << std::endl << "merge check" << std::endl;

        auto testVec1(testVecInput1);
        std::sort(testVec1.begin(), testVec1.end());

        auto testVec2(testVecInput2);
        std::sort(testVec2.begin(), testVec2.end());

        Merging::doMerge(testVec1, testVec2);

        auto testVec3(testVecInput3);
        std::sort(testVec3.begin(), testVec3.end());

        auto testVec4(testVecInput4);
        std::sort(testVec4.begin(), testVec4.end());

        Merging::doMerge(testVec3, testVec4);
    }

    // Inplace mMerge
    {
        std::cout << std::endl << "inplace merge check" << std::endl;

        auto testVec1(testVecInput1);
        auto middleIter1 = Utils::getMiddleIterator(testVec1);
        std::sort(testVec1.begin(), middleIter1);
        std::sort(middleIter1, testVec1.end());

        Merging::doInplaceMerge(testVec1, middleIter1);

        auto testVec3(testVecInput3);
        auto middleIter3 = Utils::getMiddleIterator(testVec3);
        std::sort(testVec3.begin(), middleIter3);
        std::sort(middleIter3, testVec3.end());

        Merging::doInplaceMerge(testVec3, middleIter3);
    }

    return EXIT_SUCCESS;
}
