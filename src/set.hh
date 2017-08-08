#pragma once

#include <algorithm>
#include <cassert>

#include "utils.hh"

namespace Algorithms
{

namespace Set
{

template<typename T>
void doIncludes(const T& container1, const T& container2)
{
    Utils::printContainer(container1, "Input1");
    Utils::printContainer(container2, "Input2");

    auto result = std::includes(container1.begin(), container1.end(),
                                container2.begin(), container2.end());

    Utils::printResult(result, "Input1 includes input2");
}

template<typename T>
void doSetUnion(const T& container1, const T& container2)
{
    Utils::printContainer(container1, "Input1");
    Utils::printContainer(container2, "Input2");

    T outContainer;
    std::set_union(container1.begin(), container1.end(),
                   container2.begin(), container2.end(),
                   std::back_inserter(outContainer));


    Utils::printContainer(outContainer, "Union");
}

template<typename T>
void doSetIntersection(const T& container1, const T& container2)
{
    Utils::printContainer(container1, "Input1");
    Utils::printContainer(container2, "Input2");

    T outContainer;
    std::set_intersection(container1.begin(), container1.end(),
                          container2.begin(), container2.end(),
                          std::back_inserter(outContainer));


    Utils::printContainer(outContainer, "Intersection");
}

template<typename T>
void doSetDifference(const T& container1, const T& container2)
{
    Utils::printContainer(container1, "Input1");
    Utils::printContainer(container2, "Input2");

    T outContainer;
    std::set_difference(container1.begin(), container1.end(),
                        container2.begin(), container2.end(),
                        std::back_inserter(outContainer));


    Utils::printContainer(outContainer, "Difference");
}

template<typename T>
void doSetSymmetricDifference(const T& container1, const T& container2)
{
    Utils::printContainer(container1, "Input1");
    Utils::printContainer(container2, "Input2");

    T outContainer;
    std::set_symmetric_difference(container1.begin(), container1.end(),
                                  container2.begin(), container2.end(),
                                  std::back_inserter(outContainer));


    Utils::printContainer(outContainer, "Symmetric difference");
}

}

}
