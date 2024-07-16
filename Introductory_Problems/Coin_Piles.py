def coin_piles(a, b):
    if ((2*b - a) % 3 == 0 and (2*b - a) >= 0) and ((2 * a - b) % 3 == 0 and (2*a - b) >= 0) :
        return "YES"
    return "NO"

if __name__ == "__main__" :
    t = int(input())
    for _ in range(t) :
        a, b = input().split(" ")
        a, b = int(a), int(b)
        print(coin_piles(a, b))