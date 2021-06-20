// A DNA sequence can be represented as a string consisting of the letters A, C, G and T, which correspond to the types of successive nucleotides in the sequence. Each nucleotide has an impact factor, which is an integer. Nucleotides of types A, C, G and T have impact factors of 1, 2, 3 and 4, respectively. You are going to answer several queries of the form: What is the minimal impact factor of nucleotides contained in a particular part of the given DNA sequence?

// The DNA sequence is given as a non-empty string S = S[0]S[1]...S[N-1] consisting of N characters. There are M queries, which are given in non-empty arrays P and Q, each consisting of M integers. The K-th query (0 ≤ K < M) requires you to find the minimal impact factor of nucleotides contained in the DNA sequence between positions P[K] and Q[K] (inclusive).

// For example, consider string S = CAGCCTA and arrays P, Q such that:

//     P[0] = 2    Q[0] = 4
//     P[1] = 5    Q[1] = 5
//     P[2] = 0    Q[2] = 6
// The answers to these M = 3 queries are as follows:

// The part of the DNA between positions 2 and 4 contains nucleotides G and C (twice), whose impact factors are 3 and 2 respectively, so the answer is 2.
// The part between positions 5 and 5 contains a single nucleotide T, whose impact factor is 4, so the answer is 4.
// The part between positions 0 and 6 (the whole string) contains all nucleotides, in particular nucleotide A whose impact factor is 1, so the answer is 1.
// Write a function:

// vector<int> solution(string &S, vector<int> &P, vector<int> &Q);

// that, given a non-empty string S consisting of N characters and two non-empty arrays P and Q consisting of M integers, returns an array consisting of M integers specifying the consecutive answers to all queries.

// Result array should be returned as a vector of integers.

// For example, given the string S = CAGCCTA and arrays P, Q such that:

//     P[0] = 2    Q[0] = 4
//     P[1] = 5    Q[1] = 5
//     P[2] = 0    Q[2] = 6
// the function should return the values [2, 4, 1], as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [1..100,000];
// M is an integer within the range [1..50,000];
// each element of arrays P, Q is an integer within the range [0..N − 1];
// P[K] ≤ Q[K], where 0 ≤ K < M;
// string S consists only of upper-case English letters A, C, G, T.

#include <vector>
#include "solutions.hpp"

namespace GenomicRangeQuery {
    std::vector<int> create_prefix_sum(std::string &S, char letter) {
        int num_elements = S.size();
        std::vector<int> values;
        if (S[0] == letter) {
            values.push_back(1);
        } else {
            values.push_back(0);
        }
        for (int i = 1; i < num_elements; i++) {
            values.push_back(0);
            if (S[i] == letter) {
                values[i] = 1 + values[i - 1];
            } else {
                values[i] = values[i - 1];
            }
        }
        return values;
    }

    bool exists_in_range(std::vector<int> &values, int p, int q) {
        if (p == q && p > 0) {
            return values[p] > values[p - 1];
        } else if (p == q) {
            return values[p] == 1;
        }
        

        if (p > 0 && (values[q] - values[p - 1]) > 0) {
            return true;
        } else if (p == 0 && values[p] > 0) {
            return true;
        } else if (p == 0 && (values[q] - values[p]) > 0) {
            return true;
        }
        return false;
    }

    int get_min_impact_factor(
        std::vector<int> &values_A,
        std::vector<int> &values_C,
        std::vector<int> &values_G,
        std::vector<int> &values_T,
        int p,
        int q
    ) {
        if (exists_in_range(values_A, p, q)) {
            return 1;
        }
        if (exists_in_range(values_C, p, q)) {
            return 2;
        }
        if (exists_in_range(values_G, p, q)) {
            return 3;
        }
        if (exists_in_range(values_T, p, q)) {
            return 4;
        }
        return 9;
    }


    std::vector<int> solution(std::string &S, std::vector<int> &P, std::vector<int> &Q) {
        std::vector<int> values_A = create_prefix_sum(S, 'A');
        std::vector<int> values_C = create_prefix_sum(S, 'C');
        std::vector<int> values_G = create_prefix_sum(S, 'G');
        std::vector<int> values_T = create_prefix_sum(S, 'T');
        int num_queries = P.size();
        std::vector<int> result;
        for (int i = 0; i < num_queries; i++) {
            result.push_back(get_min_impact_factor(
                values_A,
                values_C,
                values_G,
                values_T,
                P[i],
                Q[i]
            ));
        }
        return result;

    }

}