# Uses python3
import sys

def gcd_naive(a, b):
    current_gcd = 1
    for d in range(2, min(a, b) + 1):
        if a % d == 0 and b % d == 0:
            if d > current_gcd:
                current_gcd = d

    return current_gcd

def gcd(a, b):
    if a > b:
        if b is 0:
            return a
        else:
            return gcd(b, a % b)
    elif a < b:
        if a is 0:
            return b
        else:
            return gcd(a, b % a)
    else:
        return a

if __name__ == "__main__":
    input = sys.stdin.read()
    a, b = map(int, input.split())
#    print(gcd_naive(a, b))
    print(gcd(a, b))
