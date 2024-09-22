def apartment(n, m, applicants : list[int] , apartment_sizes : list[int], difference : int) -> None :
    pointer1 : int = 0
    pointer2 : int = 0
    count : int = 0
    while (pointer1 < n and pointer2 < m) :
        diff : int = applicants[pointer1] - apartment_sizes[pointer2]
     
        if (abs(diff) <= difference) :
            count += 1
            pointer1 += 1
            pointer2 += 1
        else :
            if diff > 0 :
                pointer2 += 1
            else :
                pointer1 += 1
    
    print(count)
    
if __name__ == "__main__" :
    n, m, k = map(int, input().split())
    applicants : list[int] = sorted([int(x) for x in input().split()])
    apartment_sizes : list[int]= sorted([int(x) for x in input().split()])
    apartment(n, m, applicants, apartment_sizes, k)