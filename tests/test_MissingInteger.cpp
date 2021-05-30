#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "solutions.hpp"

using namespace std;
using std::vector;

TEST(MissingInteger, solution) {
    std::vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(5);
    test.push_back(8);


    int result = MissingInteger::solution(test);
    EXPECT_EQ(result, 4);
}
