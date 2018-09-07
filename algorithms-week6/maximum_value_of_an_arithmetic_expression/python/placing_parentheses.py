# Uses python3
import sys

def evalt(a, b, op):
    if op == '+':
        return a + b
    elif op == '-':
        return a - b
    elif op == '*':
        return a * b
    else:
        assert False

def MinAndMax(i, j, m, M, op):
    minimum = sys.maxsize
    maximum = -sys.maxsize

    for k in range(i, j):
        a = evalt(M[i][k], M[k+1][j], op[k])
        b = evalt(M[i][k], m[k+1][j], op[k])
        c = evalt(m[i][k], M[k+1][j], op[k])
        d = evalt(m[i][k], m[k+1][j], op[k])

        minimum = min(minimum, a, b, c, d)
        maximum = max(maximum, a, b, c, d)

    return minimum, maximum

def get_maximum_value(dataset):
    data_len = len(dataset)
    n = int((data_len + 1) / 2)
    d = []
    op = []
    m = [[0] * n for _ in range(n)]
    M = [[0] * n for _ in range(n)]

    for i in range(data_len):
        if i % 2 == 0:
            d.append(int(dataset[i]))
        else:
            op.append(dataset[i])

    for i in range(n):
        m[i][i] = d[i]
        M[i][i] = d[i]

    for s in range(1, n):
        for i in range(n-s):
            j = i + s

            minimum, maximum = MinAndMax(i, j, m, M, op)
            m[i][j] = minimum
            M[i][j] = maximum

    return M[0][n-1]


if __name__ == "__main__":
    print(get_maximum_value(input()))
