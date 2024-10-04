#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class CoinCombinations
{
public:
    int *memo;
    int MOD = 1e9 + 7;
    CoinCombinations(int x)
    {
        memo = new int[x + 1];
        memset(memo, 0, (x + 1) * sizeof(int));
        memo[0] = 1;
    }

    int solve(int n, int x, int coins[])
    {
        for (int j = 0; j < n; j++)
        {
            int c = coins[j];
            for (int i = 0; i <= x; i++)
            {
                if (memo[i] < 1)
                    continue;

                if (c + i <= x)
                {
                    memo[c + i] += memo[i];
                    memo[c + i] %= MOD;
                }
            }
        }
        return memo[x];
    }
};

int main()
{
    int n, x;
    cin >> n >> x;
    int coins[n];
    for (int &x : coins)
    {
        cin >> x;
    }

    CoinCombinations CC(x);
    cout << CC.solve(n, x, coins);

    return 0;
}