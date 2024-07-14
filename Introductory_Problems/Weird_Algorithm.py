def weirdAlgorithm(n):
    while (n != 1) :
        print(f"{n} ")
        n = n*3 + 1 if (n%2 == 1) else n // 2 
    print(1)
    
if __name__ == "__main__" :
    n = int(input())
    weirdAlgorithm(n)