#ifndef SOLUTIONS_HPP
#define SOLUTIONS_HPP

#include <vector>
#include <string>

namespace MaxCounters {
    std::vector<int> solution(int N, std::vector<int> &A);
}

namespace MissingInteger {
    int solution(std::vector<int> &A);
}

namespace PermCheck {
    int solution(std::vector<int> &A);
}

namespace CountDiv {
    int solution(int A, int B, int K);
}

namespace GenomicRangeQuery {
    std::vector<int> solution(std::string &S, std::vector<int> &P, std::vector<int> &Q);
}

#endif