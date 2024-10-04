#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class CoinCombinations {
    public:
    int *memo;
    int MOD = 1e9+7;
    CoinCombinations(int x) {
        memo = new int[x + 1];
        memset(memo, 0, (x + 1) * sizeof(int));
        memo[0] = 1;
    }

    int solve (int n, int x, int coins[]) {
        for (int i = 0; i <= x; i++) {
            for (int j = 0; j < n; j++ ) {
                int coin = coins[j];
                if (coin + i <= x) {
                    memo[i + coin] += memo[i];
                    memo[i + coin] %= MOD;
                }
            }
        }
        return memo[x];
    }
};

int main () {
    int n, x;
    cin >> n >> x;

    int coins[n];

    for (int& c : coins) {
        cin >> c;
    } 

    CoinCombinations CC(x);
    cout << CC.solve(n, x, coins);
    return 0;
}