#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
class MinimizingCoins {
    public :
    int *memo;
    
    MinimizingCoins (int x) {
        memo =   new int[x + 1];
        memset(memo, -1, (x + 1) * sizeof(int));
        memo[0] = 0;
    }   

    // Top Down Approach  
    int solve (int x, int n, int coins[]) {
        for (int i = 0; i <= x; i++) {
            if (memo[i] == -1) continue;
            for (int j = 0 ; j < n; j++) {
                if (i + coins[j] <= x && (memo[i + coins[j]] == -1 || memo[i + coins[j]] > memo[i] + 1)) {
                        memo[i + coins[j]] = memo[i] + 1;
                    }
                }
            }
        return memo[x];
    }

};

int main() {
    int n, x;

    cin >> n >> x;
    int coins[n];
    for (int& c : coins) {
        cin >> c;
    }

    MinimizingCoins MC(x);
    cout << MC.solve(x, n, coins);

    
    return 0; 
}