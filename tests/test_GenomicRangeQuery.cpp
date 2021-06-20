#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "solutions.hpp"

using namespace std;
using std::vector;

TEST(GenomicRangeQuery, solution) {
    std::vector<int> P;
    P.push_back(2);
    P.push_back(5);
    P.push_back(0);
    std::vector<int> Q;
    Q.push_back(4);
    Q.push_back(5);
    Q.push_back(6);

    string S = "CAGCCTA";

    std::vector<int> expected;
    expected.push_back(2);
    expected.push_back(4);
    expected.push_back(1);

    std::vector<int> result = GenomicRangeQuery::solution(S, P, Q);
    EXPECT_EQ(result, expected);
}
