result = float('inf')

def apple_division(n, a, b, i, apples) :
    global result
    if (i >= n):
        result = min(result, abs(a - b))
        return
    
    apple_division(n, a + apples[i], b, i + 1, apples)
    apple_division(n, a, b + apples[i], i + 1, apples)
    

if __name__ == "__main__":
    n = int(input())
    apples = list(map (int, input().split()))
    apple_division(n, 0, 0, 0, apples)
    print(result)
    