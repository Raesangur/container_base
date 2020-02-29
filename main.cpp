
#include "container_base.h"
#include "iterator_base.h"

#include "testContainer.hpp"

#include <iostream>

int main()
{
    pel::testContainer<int> test;
    test.at(0);
    test[0];
    test.begin();
    test.front();
    test.back();
    test.cend();

    return 0;
}