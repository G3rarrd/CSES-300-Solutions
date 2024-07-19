#include <bits/stdc++.h>

using namespace std;

// Greedy Approach 

long long stickLengths(int n, vector<int> integers) {
    int median = integers[n / 2];
    long long res = 0;
    for (int i =0; i < n; i++) {
        res += abs(integers[i] - median);
    }
    return res;
}


int main() {
    int n;
    cin >> n;
    vector<int> integers;
    
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        integers.emplace_back(p);
    }

    sort(integers.begin(), integers.end());
    cout << stickLengths(n, integers);
    
    return 0;
}