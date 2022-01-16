
def solution(A):
    # write your code in Python 3.6
    # find maximum slice, and then remove smallest element
    max_slice = 0
    sum_A = sum(A)
    max_ending = A[1]
    min_value = A[1]
    for i in range(2, len(A) - 1):
        if A[i] < min_value:
            min_value = A[i]
        if (max_ending + A[i]) < 0:
            min_value = A[i]
        max_ending = max(0, max_ending + A[i])

        max_slice = max(max_slice, max_ending - min_value)

    return max_slice