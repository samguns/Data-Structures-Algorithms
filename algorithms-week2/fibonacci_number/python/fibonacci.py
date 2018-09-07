# Uses python3
def calc_fib(n):
    fibs = [1, 1]
    if n <= 1:
        return n

    for i in range(2, n):
        fibs.append(fibs[i-2] + fibs[i-1])

    return fibs[n-1]

n = int(input())
print(calc_fib(n))
