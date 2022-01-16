def solution(A):
    num_passes = 0

    n = len(A)
    number_of_zeros = 0
    for i in range(n):
        if A[i] == 0:
            number_of_zeros = number_of_zeros + 1
        elif A[i] == 1:
            num_passes = num_passes + number_of_zeros

    if num_passes > 1000000000:
        return -1

    return num_passes