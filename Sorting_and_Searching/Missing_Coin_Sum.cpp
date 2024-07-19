#include <bits/stdc++.h>

using namespace std;

// Greedy Approach
long long missingCoinSum(int n, vector<long long> coins) {
    long long res = 0;
    for (int i = 0; i < n; i++) {
        if (res + 1 < coins[i]) {
            return res + 1;
        }
        res += coins[i];
    }
    return res+1;
}

int main() {
    int n;
    cin >> n;
    vector<long long> coins;

    for(int i = 0; i < n; i++) {
        long long c;
        cin >> c;
        coins.emplace_back(c);
    } 

    sort(coins.begin(), coins.end());
    cout << missingCoinSum(n, coins);
    return 0;
}