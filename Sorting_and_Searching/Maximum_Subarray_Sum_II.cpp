#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


ll maximumSubArraySum (vector<ll> array, int n, int b, int a) {
    deque<ll> dq;
    vector<ll> prefixArray(n + 1);
    ll res = LLONG_MIN;

    for (int i = 1; i< n + 1; i++) {
        prefixArray[i] += prefixArray[i-1] + array[i-1];
    }

    for (int i = a; i < n + 1; i++) {
        
        if (!dq.empty() && i - dq.front() > b) {
            dq.pop_front();
        }
        
        while (!dq.empty() && prefixArray[dq.back()] > prefixArray[i - a]) {
            dq.pop_back();
        }
        
        dq.emplace_back(i - a);
        res = max(res, prefixArray[i] - prefixArray[dq.front()]);
    }
    return res;
}



int main() {
    int n;
    int a, b;
    cin >> n;
    cin >> a;
    cin >> b;
    vector<ll> array;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        array.emplace_back(x);
    }

    ll res = maximumSubArraySum(array, n, b, a);
    cout << res;
    return 0;
}