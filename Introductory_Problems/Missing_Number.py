# Math method
# 1. Use Gaussian summation to calculate the sum of numbers from 1 to n

# 2. Get the total of the inputted values

# 3. Subtract the total of the inputted values from the gaussian sum to get
# the missing number

def missingNumber(n):
    ans = n * (n + 1) // 2 # Gaussian Summation
    total = sum(list(map(int, input().split())))
    return ans - total

if __name__ == "__main__":
    n = int(input())
    print(missingNumber(n))