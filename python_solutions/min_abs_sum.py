def solution(A):
    n_elements = len(A)
    A_abs = [abs(a) for a in A]
    max_value = max(A_abs)
    counter = [0] * (max_value + 1)
    for value in A_abs:
        counter[value] = counter[value] + 1
    print(counter)

    sum_A = sum(A_abs)
    dp = [-1] * (sum_A + 1)
    dp[0] = 0
    for a in range(1, max_value + 1):
        print(dp)
        if counter[a] > 0:
            for j in range(sum_A):
                if dp[j] >= 0:
                    dp[j] = counter[a]
                elif (j >= a and dp[j - a] > 0):
                    dp[j] = dp[j - a] - 1
    print(dp)

solution([1, 5, 2, -2])