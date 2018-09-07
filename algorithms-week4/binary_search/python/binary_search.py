# Uses python3
import sys

def binary_search(a, x):
    left, right = 0, len(a)
    middle = int(right / 2)

    if a[left] > x or a[right-1] < x:
        return -1

    if a[middle] == x:
        return middle
    elif middle == 0:
        return -1

    if a[middle] > x:
        return binary_search(a[:middle], x)
    else:
        found = binary_search(a[middle+1:], x)
        return (found + middle + 1)

def linear_search(a, x):
    for i in range(len(a)):
        if a[i] == x:
            return i
    return -1

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    m = data[n + 1]
    a = data[1 : n + 1]
    for x in data[n + 2:]:
        # replace with the call to binary_search when implemented
        print(binary_search(a, x), end = ' ')
