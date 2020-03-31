#include "src/container_base.h"
#include "src/iterator_base.h"

#include "test/testContainer.hpp"

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

int
main()
{
    std::array<int, 5> b {1, 2, 3, 4, 5};
    int&               a = b.at(0);

    pel::iterator_base<int> testBegin(&b.front());
    pel::iterator_base<int> testEnd(&b.back() + 1);

    std::vector<int> testVec = std::vector<int> {testBegin.ptr(), testEnd.ptr()};

    for(int test: testVec)
    {
        std::cout << test;
    }

    std::for_each(testBegin, testEnd, [](int test) {
        std::cout << test;
    });

    return a;
}
