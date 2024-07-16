def numberSpiral(n):
    for _ in range(n) :
        y, x = map(int, input().split())
        m = max(y, x)
        start = ((m*m) - m) + 1
        
        if (y == x) :
            print(start)
            continue
        
        if (y > x) :
            print(start + (y - x) if (y%2 == 0)  else start - (y - x))
        
        else:
            print (start - (x - y) if (x%2 == 0) else start + (x - y))

if __name__ == "__main__" :
    numberSpiral(int(input()))  