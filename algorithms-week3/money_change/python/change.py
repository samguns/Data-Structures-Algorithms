# Uses python3
import sys

def get_change(m):
    denomination = [10, 5, 1]
    n = 0

    for d in denomination:
        while m >= d:
            n += int(m / d)
            m = m % d

    return n

if __name__ == '__main__':
    m = int(sys.stdin.read())
    print(get_change(m))
