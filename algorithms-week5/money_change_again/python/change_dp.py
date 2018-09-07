# Uses python3
import sys

def get_change(m):
    NumCoins = 0
    MinNumCoins = []
    MinNumCoins.append(0)
    Coins = [1, 3, 4]

    for i in range(1, m+1):
        MinNumCoins.append(i + 1)

        for coin in list(Coins):
            if i >= coin:
                NumCoins = MinNumCoins[i-coin] + 1

            if NumCoins < MinNumCoins[i]:
                MinNumCoins[i] = NumCoins

    return MinNumCoins[m]

if __name__ == '__main__':
    m = int(sys.stdin.read())
    print(get_change(m))
