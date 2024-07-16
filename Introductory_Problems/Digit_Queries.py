def digitQueries(k):
    if (k < 10) :
        return k
    
    pow10 = 10
    digits = 1
    
    startInterval = 0
    endInterval = 9
    
    while (True) :
        startInterval = endInterval + 1
        digits += 1
        endInterval += (9 * pow10 * digits)
        
        
        if (k <= endInterval) : break
        
        pow10*=10
        
    number = ((k - startInterval) // digits) + pow10
    index = (k - startInterval) % digits
    return str(number)[index]

if __name__ == "__main__" :
    q = int(input())
    
    for _ in range(q) :
        k = int(input())
        print(digitQueries(k))
    
    
    
    
        
        
    
