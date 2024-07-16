def repetitions(s):
    n = len(s)
    i = 0
    maxRep = 1
    while(i < n):
        j = i + 1
        
        while (j < n and s[i] == s[j] ) :
            j += 1
            
        maxRep = max(maxRep, (j - i) )
        i = j
        
    return maxRep


if __name__ == "__main__" :
    s = input()
    print(repetitions(s))