#include <bits/stdc++.h>

using namespace std;

class DiceCombinations
{
private:
    int *memo;
    int MOD = 1e9 + 7;

public:
    DiceCombinations(int size)
    {
        memo = new int[size + 1];
        memset(memo, 0, (size + 1) * sizeof(int));
        memo[0] = 1;
    };

    int solve(int n)
    {
        if (memo[n] != 0)
        {
            return memo[n];
        }

        for (int i = 1; i <= 6; i++)
        {
            if (n - i >= 0)
            {
                memo[n] += solve(n - i);
                memo[n] %= MOD;
            }
        }

        return memo[n];
    }
};

int main()
{
    int n;
    cin >> n;

    DiceCombinations DC(n);

    cout << DC.solve(n);

    return 0;
}