// Write a function:

// int solution(vector<int> &A);

// that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

// For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

// Given A = [1, 2, 3], the function should return 4.

// Given A = [−1, −3], the function should return 1.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [1..100,000];
// each element of array A is an integer within the range [−1,000,000..1,000,000].

#include <set>
#include <vector>
#include "solutions.hpp"

namespace MissingInteger {
    int solution(std::vector<int> &A) {
        std::set<int> values;
        int number_of_elements = A.size();
        for (int i = 0; i < number_of_elements; i++) {
            values.insert(A[i]);
        }
        int counter = 1;
        std::set<int>::iterator it;
        for (it=values.begin(); it!=values.end(); ++it) {
            if (*it > 0 && counter != *it) {
                return counter;
            }
            if (*it > 0) {
                counter = counter + 1;
            }
        }
        return counter;
    }
}