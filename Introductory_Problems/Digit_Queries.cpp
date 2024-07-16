#include <bits/stdc++.h>

using namespace std;


int digitQueries(long long k) {
    if (k < 10) {
        return k;
    }

    // Initializing the start and end intervals
    long long startInterval = 0;
    long long endInterval = 9;

    long long pow10 = 10;
    long long digits = 1;

    while (true) {
        startInterval = endInterval + 1; 
        digits++;
        endInterval += 9*pow10*digits;
        if (k <= endInterval) break;
        pow10 *= 10;
    }

    long long number = ((k - startInterval) / digits) + pow10;
    long long index = (k - startInterval) % digits;

    string numToString = to_string(number);

    int res =  numToString[index] - '0';
    return  res; 
}

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        long long k;
        cin >> k;
        cout << digitQueries(k) << endl;
    }
    return 0;
}