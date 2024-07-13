#include <bits/stdc++.h>
using namespace std;

long long fastModularExpo(long long base, long long expo) {
    long long MOD = 1e9 + 7;
    int res = 1;
    while (expo > 0) {
        if (expo & 1LL) {
            res = (res*base) % MOD;
        }
        base = (base*base) % MOD;
        expo >>= 1LL;
    }
    return res;
}

int main() {
    int n ;
    cin >> n;
    
    cout << fastModularExpo(2, n);
    return 0;
}