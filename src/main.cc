#include <iostream>
#include <vector>

#include "utils.hh"
#include "sortingalgorithms.hh"

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

        std::vector<int> testVec1;
        std::copy(testVecInput1.begin(), testVecInput1.end(), std::back_inserter(testVec1));

        Utils::print(testVec1, "Input");
        SortingAlgorithms::checkSort(testVec1);
        Utils::print(testVec1, "Output");

        std::vector<std::pair<int, int>> testVec2;
        std::copy(testVecInput2.begin(), testVecInput2.end(), std::back_inserter(testVec2));

        Utils::print(testVec2, "Input");
        SortingAlgorithms::checkSort(testVec2);
        Utils::print(testVec2, "Output");
    }

    // Stable sort
    {
        std::cout << std::endl << "Stable sorting" << std::endl;

        std::vector<int> testVec1;
        std::copy(testVecInput1.begin(), testVecInput1.end(), std::back_inserter(testVec1));

        Utils::print(testVec1, "Input");
        SortingAlgorithms::checkStableSort(testVec1);
        Utils::print(testVec1, "Output");

        std::vector<std::pair<int, int>> testVec2;
        std::copy(testVecInput2.begin(), testVecInput2.end(), std::back_inserter(testVec2));

        Utils::print(testVec2, "Input");
        SortingAlgorithms::checkStableSort(testVec2);
        Utils::print(testVec2, "Output");
    }

	return 0;
}
