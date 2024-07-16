def int_to_binary(num, n) :
    binary = ["0"] * n
    i = 0
    while (num > 0) :
        binary[i] = str(num & 1)
        num >>= 1
        i += 1
        
    return''.join(binary[::-1])


def gray_code(n) :
    for i in range(2**n) :
        print(int_to_binary((i >> 1) ^ i, n))
        
if __name__ == "__main__" :
    n = int(input())
    gray_code(n)