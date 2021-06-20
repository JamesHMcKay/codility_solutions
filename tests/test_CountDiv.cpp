#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "solutions.hpp"

using namespace std;
using std::vector;

TEST(CountDiv, solution) {
    EXPECT_EQ(CountDiv::solution(0, 0, 11), 1);
    EXPECT_EQ(CountDiv::solution(11, 345, 17), 20);
}
