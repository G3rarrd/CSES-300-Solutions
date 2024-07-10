#include <bits/stdc++.h>
using namespace std;

int main() {
    string sequence;
    cin >> sequence;

    int sequenceLength = sequence.size();
    int longestRepetition = 1;
    
    int i = 0;
    while (i < sequenceLength) {
        char currentCharacter = sequence[i];
        int repetionCount = 1;
        i++;

        while (currentCharacter == sequence[i]) {
            repetionCount++;
            i++;
        }

        longestRepetition = max(longestRepetition, repetionCount);
    }

    cout << longestRepetition;
    return 0;
}