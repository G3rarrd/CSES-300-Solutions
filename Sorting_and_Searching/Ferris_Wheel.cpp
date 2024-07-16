#include <bits/stdc++.h>
using namespace std;
 
long long ferrisWheel(long long  n, long long  x) {
    vector<long long > weights;
    for (int i = 0; i < n; i++) {
        long long p;
        cin >> p;
        weights.emplace_back(p);
    }
 
    sort(weights.begin(), weights.end());
 
    int lo = 0;
    int hi = n - 1;
    long long res = 0;
    while (hi > lo) {
        long long total = weights[hi];
        if(weights[hi] + weights[lo] <= x) {
            lo++;
            hi--;
            res++;
        } else {
            hi--;
        }
        
    } 
 
    return n - res;
}
 
int main() {
    long long  n;
    long  long x;
    cin >> n;
    cin >> x;
    cout << ferrisWheel(n, x);
    return 0;
}