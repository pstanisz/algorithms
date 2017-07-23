#pragma once

#include <utility>
#include <iostream>

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

}
