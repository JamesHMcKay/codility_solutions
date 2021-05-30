#include <vector>
#include "MaxCounters.hpp"

using namespace std;
using std::vector;
namespace MaxCounters {
    std::vector<int> get_new_counter(int N, int value) {
        std::vector<int> counters;
        for (int i = 0; i < N; i++) {
            counters.push_back(value);
        }
        return counters;
    }

    std::vector<int> solution(int N, std::vector<int> &A) {
        int num_operations = A.size();

        std::vector<int> counters = get_new_counter(N, 0);
        int max_counter = 0;
        int min_counter = 0;
        for (int i = 0; i < num_operations; i++) {
            if (A[i] <= N) {
                if (counters[A[i] - 1] < min_counter) {
                    counters[A[i] - 1] = min_counter;
                }

                counters[A[i] - 1] = counters[A[i] - 1] + 1;
                if (counters[A[i] - 1] > max_counter) {
                    max_counter = counters[A[i] - 1];
                }
            } else {
                min_counter = max_counter;
            }
        }

        for (unsigned int i = 0; i < N; i++) {
            if (counters[i] < min_counter) {
                counters[i] = min_counter;
            }
        }

        return counters;
    }
}
