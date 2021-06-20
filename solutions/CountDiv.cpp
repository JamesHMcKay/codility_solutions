// Write a function:

// int solution(int A, int B, int K);

// that, given three integers A, B and K, returns the number of integers within the range [A..B] that are divisible by K, i.e.:

// { i : A ≤ i ≤ B, i mod K = 0 }

// For example, for A = 6, B = 11 and K = 2, your function should return 3, because there are three numbers divisible by 2 within the range [6..11], namely 6, 8 and 10.

// Write an efficient algorithm for the following assumptions:

// A and B are integers within the range [0..2,000,000,000];
// K is an integer within the range [1..2,000,000,000];
// A ≤ B.

#include <set>
#include <vector>
#include "solutions.hpp"

namespace CountDiv {

    int solution(int A, int B, int K) {
        int count = 0;
        int i = A;
        while (count == 0 and i <= B) {
            if (i % K == 0) {
                count = count + 1;
            }
            i = i + 1;
        }
        if (i < B) {
            int difference = B - i;
            count = count + difference / K;
        }
        if (A != B && B % K == 0) {
            count = count + 1;
        }
        return count;
    }
}