from dataclasses import dataclass
@dataclass
class Pair:
    first : int
    second : int
    
def collectingNumbers(numsPairs : list[Pair], n : int) :
    i : int = 0
    rounds : int = 0
    while (i < n) :
        while (i < n - 1 and numsPairs[i].second < numsPairs[i + 1].second) :
            i += 1    
        
        rounds += 1
        i += 1
    
    print(rounds)

if __name__ == '__main__' :
    n : int = int(input())
    numsInput : list[int] = list(map(int, input().split()) )
    numsPairs : list[Pair] = sorted([Pair(numsInput[i], i) for i in range(0, len(numsInput))], key=lambda p : p.first)
    collectingNumbers(numsPairs, n)
