#pragma once

#include <utility>
#include <iostream>
#include <algorithm>

namespace Algorithms
{

namespace Utils
{

const char* UNDERLINED      = "\33[4m";
const char* NO_UNDERLINED   = "\33[0m";

template <typename T, typename U>
std::ostream& operator<<(std::ostream& stream, const std::pair<T, U>& item)
{
    stream << "(" << item.first << ", " << item.second << ")";

    return stream;
}

template <typename T>
void printContainer(const T& container, std::string prefix = std::string(""))
{
    if (!prefix.empty())
    {
        std::cout << prefix << ":\t";
    }

    for(auto item : container)
    {
        std::cout << item << " ";
    }

    std::cout << std::endl;
}

template <typename T>
void highlightSingle(const T& container,
                    typename T::const_iterator position,
                    std::string prefix = std::string(""))
{
    if (!prefix.empty())
    {
        std::cout << prefix << ":\t";
    }

    for(auto iter = container.begin(); iter < container.end(); ++iter)
    {
        if (iter == position)
        {
            std::cout << UNDERLINED << *iter << NO_UNDERLINED;
        }
        else
        {
            std::cout << *iter;
        }

        std::cout << " ";
    }

    std::cout << std::endl;
}

template <typename T>
void highlightRange(const T& container,
                    typename T::const_iterator first,
                    typename T::const_iterator second,
                    std::string prefix = std::string(""))
{
    if (!prefix.empty())
    {
        std::cout << prefix << ":\t";
    }

    for (auto iter = container.begin(); iter < container.end();)
    {
        if (iter == first)
        {
            std::cout << UNDERLINED << *iter;
        }
        else
        {
            std::cout << *iter;
        }

        if (++iter == second)
        {
            std::cout << NO_UNDERLINED;
        }

        std::cout << " ";
    }

    std::cout << std::endl;
}

template <typename T>
void printResult(T result, std::string prefix)
{
    if (!prefix.empty())
    {
        std::cout << prefix << ":\t";
    }

    std::cout << result << std::endl;
}

template <>
void printResult<bool>(bool result, std::string prefix)
{
    if (!prefix.empty())
    {
        std::cout << prefix << ":\t";
    }

    std::cout << std::boolalpha << result << std::noboolalpha << std::endl;
}

template <typename T>
typename T::iterator getMiddleIterator(T& container)
{
    auto middle = container.begin();
    std::advance(middle, container.size()/2);

    return middle;
}

}

}
