#include <set>
#include <vector>
#include "solutions.hpp"

namespace MissingInteger {
    int solution(std::vector<int> &A) {
        // write your code in C++14 (g++ 6.2.0)
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