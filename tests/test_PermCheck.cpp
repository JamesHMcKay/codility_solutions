#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "solutions.hpp"

using namespace std;
using std::vector;

TEST(PermCheck, is_permutation) {
    std::vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(4);

    std::vector<int> expected;

    int result = PermCheck::solution(test);
    EXPECT_EQ(result, 0);
}

TEST(PermCheck, is_not_permutation) {
    std::vector<int> test;
    test.push_back(3);
    test.push_back(2);
    test.push_back(1);

    std::vector<int> expected;

    int result = PermCheck::solution(test);
    EXPECT_EQ(result, 1);
}

