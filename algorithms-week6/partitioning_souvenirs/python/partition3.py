# Uses python3
import sys
import itertools

def partition2(A):
    n = len(A)
    K = sum(A)
    half = int(K/2)
    P = [[False] * (n+1) for i in range(half + 1)]

    for x in range(n+1):
        P[0][x] = True

    for i in range(1, half + 1):
        for j in range(1, n+1):
            idx = i - A[j-1]
            if idx >= 0:
                prev = P[i][j-1]
                prev_subset = P[idx][j-1]
                P[i][j] = prev or prev_subset
            else:
                P[i][j] = P[i][j-1]

    return P[half][n]

def partition3(A):
    n = len(A)
    if n < 3:
        return 0
    K = sum(A)
    if K % 3 != 0:
        return 0
    third = int(K/3)
    P = [[0] * (n+1) for i in range(K + 1)]

    for x in range(n+1):
        P[0][x] = 1

    for i in range(1, K + 1):
        for j in range(1, n+1):
            idx = i - A[j-1]
            if idx >= 0:
                prev = P[i][j-1]
                prev_subset = P[idx][j-1]
                P[i][j] = prev or prev_subset
            else:
                P[i][j] = P[i][j-1]

            if (i == third or i == 2 * third) and j == n:
                if P[i][j] != 1:
                    return 0

    return P[K][n]

if __name__ == '__main__':
    input = sys.stdin.read()
    n, *A = list(map(int, input.split()))
    print(partition3(A))

