# Uses python3
import sys

def optimal_sequence(n):
    sequence = []
    ops = [0, 0]
    denominator = [2, 3]

    for i in range(2, n+1):
        ops.append(ops[i-1] + 1)

        for div in list(denominator):
            if (i % div) == 0:
                min = ops[int(i / div)]
                if min < ops[i]:
                    ops[i] = min + 1

    sequence.append(n)
    while n > 1:
        min_op = ops[n-1]
        m = n-1

        for div in list(denominator):
            if (n % div) == 0:
                op = ops[int(n / div)]
                if op < min_op:
                    min_op = op
                    m = int(n / div)

        sequence.append(m)
        n = m

    return reversed(sequence)

input = sys.stdin.read()
n = int(input)
sequence = list(optimal_sequence(n))
print(len(sequence) - 1)
for x in sequence:
    print(x, end=' ')