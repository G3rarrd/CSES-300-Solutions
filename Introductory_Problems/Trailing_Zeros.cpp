#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int pow5 = 5;
    int trailingZeros = 0;
    while (n / pow5 > 0) {
        trailingZeros += n/pow5;
        pow5 *= 5;
    }

    cout << trailingZeros;
    return 0;
}