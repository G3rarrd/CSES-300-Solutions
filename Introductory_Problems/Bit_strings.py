#Fast Modular Exponentiation

def bit_strings(expo):
    MOD = int(1e9)+7
    base = 2
    result = 1
    while (expo > 0) :
        if (expo & 1) :
            result = (result * base)%MOD 
        base = (base*base)%MOD
        expo >>= 1
    return result


if __name__ == "__main__" :
    n = int(input())
    print(bit_strings(n))
    
# Mistake : Used 1e9 + 7 instead of int(1e9) + 7
# And Use mod on the base * base operation