# Uses python3
import sys

def optimal_weight(W, w):
    n = len(w)
    values = [[0] * (W+1) for x in range(n+1)]

    for i in range(1, n+1):
        for j in range(1, W+1):
            values[i][j] = values[i-1][j]

            wi = w[i-1]
            if wi <= j:
                val = values[i-1][j-wi] + wi

                if val > values[i][j]:
                    values[i][j] = val

    return values[n][W]

if __name__ == '__main__':
    input = sys.stdin.read()
    W, n, *w = list(map(int, input.split()))
    print(optimal_weight(W, w))
