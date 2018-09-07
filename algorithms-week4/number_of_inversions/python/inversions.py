# Uses python3
import sys

def get_number_of_inversions(a, b, left, right):
    number_of_inversions = 0
    if right - left <= 0:
        return number_of_inversions
    ave = (left + right) // 2
    number_of_inversions += get_number_of_inversions(a, b, left, ave)
    number_of_inversions += get_number_of_inversions(a, b, ave+1, right)

    for s in range(left, right+1):
        b[s] = a[s]

    i = left
    j = ave+1
    for k in range(left, right+1):
        if i > ave:
            a[k] = b[j]
            j += 1
        elif j > right:
            a[k] = b[i]
            i += 1
        elif b[j] < b[i]:
            a[k] = b[j]
            j += 1
            number_of_inversions += (ave - i + 1)
        else:
            a[k] = b[i]
            i += 1

    return number_of_inversions

if __name__ == '__main__':
    input = sys.stdin.read()
    n, *a = list(map(int, input.split()))
    b = n * [0]
    print(get_number_of_inversions(a, b, 0, len(a)-1))
