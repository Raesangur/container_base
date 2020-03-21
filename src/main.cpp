
#include "container_base.h"
#include "iterator_base.h"

#include "test/testContainer.hpp"

#include <array>
#include <iostream>

int
main()
{
    constexpr std::size_t size = 10;

    std::array<int, size>   b {0};
    pel::testContainer<int> test;
    int                     a = test.at(0);
    int                     f = test[0];
    int                     c = test.front();
    int                     e = test.back();

    return a + b[0] + c + e + f;
}
