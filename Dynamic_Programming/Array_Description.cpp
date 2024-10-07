#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class ArrayDescription
{
public:
    ll **memo;
    int MOD = 1e9 + 7;
    ArrayDescription(int n, int m)
    {
        memo = new ll *[n];
        for (int i = 0; i < n; i++)
        {
            memo[i] = new ll[m + 1];
            fill(memo[i], memo[i] + (m + 1), 0); 
        }
    }

    ll iterativeSolve(ll n, ll m, ll nums[])
    {
        if (nums[0] > 0)
        {
            memo[0][nums[0]] = 1;
        }

        else
        {
             for (int j = 1; j <= m; j++)
            {
                memo[0][j] = 1;  // If nums[0] is 0, all values are valid initially
            }
        }

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > 0)
            {
                for (int j = nums[i] - 1; j <= nums[i] + 1; ++j)
                {
                    if (j > 0 && j <= m)
                    {
                        memo[i][nums[i]] += memo[i - 1][j];
                        memo[i][nums[i]] %= MOD;
                    }
                }
            }

            else
            {
                for (int k = 1; k <= m; k++)
                {
                    for (int j = k - 1; j <= k + 1; ++j)
                    {
                        if (j > 0 && j <= m)
                        {
                            memo[i][k] += memo[i - 1][j];
                            memo[i][k] %= MOD;
                        }
                    }
                }
            }
        }

        // Checking Memo
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j <= m; j++)
        //     {
        //         cout << memo[i][j] << ' ';
        //     }
        //     cout << endl;
        // }

        ll total = 0;
        for (int i = 1; i <= m; i++)
        {
            total += memo[n - 1][i];
            total %= MOD;
        }
        return total;
    }
};

int main()
{
    ll n, m;
    cin >> n >> m;
    ll nums[n];

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    ArrayDescription AD(n, m);
    cout << AD.iterativeSolve(n, m, nums);
    return 0;
}
