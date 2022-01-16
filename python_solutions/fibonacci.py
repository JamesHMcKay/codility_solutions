def fib(x):
    if x == 1:
        return 1
    if x == 0:
        return 0
    else:
        return fib(x - 1) + fib(x - 2)

def fast_fib(x):
    fib_list = [0] * (x + 2)
    fib_list[1] = 1

    for i in range(2, x + 1):
        fib_list[i] = fib_list[i - 1] + fib_list[i - 2]
    return fib_list[x]

print(fib(11))
print(fast_fib(11))