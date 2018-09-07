#Uses python3

import sys

def lcs2(a, b):
    n = len(a)
    m = len(b)
    L = [[0] * (m+1) for i in range(n+1)]

    for i in range(1, n+1):
        for j in range(1, m+1):
            if a[i-1] != b[j-1]:
                max1 = L[i][j-1]
                max2 = L[i-1][j]
                L[i][j] = max(max1, max2)

            else:
                L[i][j] = L[i-1][j-1] + 1

    return L[n][m]


if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))

    n = data[0]
    data = data[1:]
    a = data[:n]

    data = data[n:]
    m = data[0]
    data = data[1:]
    b = data[:m]

    print(lcs2(a, b))
