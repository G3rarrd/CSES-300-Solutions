#include <bits/stdc++.h>
using namespace std;

int main() {
    long long arraySize;
    cin >> arraySize;

    long long previousNumber = 0;
    long long totalMoves = 0;

    for (int i = 0; i < arraySize; i++) {
        long long number;
        cin >> number;
        long long difference = max(static_cast<long long>(0), previousNumber - number);
        totalMoves += difference;
        previousNumber = number + difference;
    }

    cout << totalMoves;

    return 0;
}