#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "solutions.hpp"

using namespace std;
using std::vector;

TEST(feature, create) {
    std::vector<int> test;
    test.push_back(1);
    test.push_back(2);
    
    std::vector<int> expected;
    expected.push_back(1);
    expected.push_back(1);
    expected.push_back(0);

    std::vector<int> result = MaxCounters::solution(3, test);
    EXPECT_EQ(result[0], expected[0]);
}
