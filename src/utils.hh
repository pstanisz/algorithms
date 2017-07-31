#pragma once

#include <utility>
#include <iostream>
#include <algorithm>

namespace Algorithms
{

namespace Utils
{

template <typename T, typename U>
std::ostream& operator<<(std::ostream& stream, const std::pair<T, U>& item)
{
    stream << "(" << item.first << ", " << item.second << ")";

    return stream;
}

template <typename T>
void print(const T& container, std::string prefix = std::string(""))
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
void print(const T& container, typename T::const_iterator position,
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
            std::cout << ">> " << *iter << " << ";
        }
        else
        {
            std::cout << *iter << " ";
        }
    }

    std::cout << std::endl;
}

template <typename T>
void print(const T& container, typename T::const_iterator first, typename T::const_iterator second,
           std::string prefix = std::string(""))
{
    if (!prefix.empty())
    {
        std::cout << prefix << ":\t";
    }

    for(auto iter = container.begin(); iter < container.end(); ++iter)
    {
        if (iter == first)
        {
            std::cout << ">> " << *iter << " ";
        }
        else if (iter == second)
        {
            std::cout << "<< " << *iter << " ";
        }
        else
        {
            std::cout << *iter << " ";
        }
    }

    std::cout << std::endl;
}

template <>
void print<const bool&>(const bool& result, std::string prefix)
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
