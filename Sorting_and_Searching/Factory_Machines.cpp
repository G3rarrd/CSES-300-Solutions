#include <bits/stdc++.h>
using namespace std;

vector<long long> machines;
long long  totalTime( long long midTime, long long t) {
    long long total = 0;
    for (long long x : machines) {
        total += (midTime / x);
        if (total >= t) break; // prevent overflow
    } 

    return total;
}

long long binSearch(long long lo, long long hi, long long target) {
    while (lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        if (totalTime(mid, target) >= target) {
            hi = mid;
            continue;
        }
        lo = mid;
    }
    return hi;
}


long long factoryMachines(long long n, long long  t) {
    
    long long maxTime = 0;
    for (int i = 0; i < n; i++) {
        long long k;
        cin >> k;
        maxTime  = max(maxTime, k);
        machines.emplace_back(k);
    }

    maxTime *= t;
    return binSearch(0, maxTime + 1, t);
}

int main() {
    long long n, t;
    cin >> n >> t;

    cout << factoryMachines(n, t);
    return 0;
}