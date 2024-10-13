#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class MoneySums
{

private:
    bool *memo;
    int memoSize;
    vector<int> distinctNums;

public:
    MoneySums(ll n, ll total)
    {
        memoSize = total;
        memo = new bool[memoSize];

        for (int i = 0; i <= memoSize; i++)
            memo[i] = false;

        memo[0] = true;
    }

    vector<int> knapsack(ll n, ll nums[])
    {

        for (int i = 0; i <= n; i++)
        {
            int j = memoSize - nums[i];

            while (j >= 0)
            {
                memo[j + nums[i]] = (memo[j] || memo[j + nums[i]]);
                
                j--;
            }
        }

        for (int i = 1; i <= memoSize; i++) {
            if (memo[i]) {
                distinctNums.emplace_back(i);
            }
        }

        return distinctNums;
    }

    void output() {
        int n = distinctNums.size();
        cout << n << endl;

        for (int& x : distinctNums) {
            cout << x << ' ';
        }
    }
};

int main()
{
    ll n;
    cin >> n;
    ll coins[n];

    ll total = 0;

    for (ll &c : coins)
    {
        cin >> c;
        total += c;
    }

    MoneySums MS(n, total);

    MS.knapsack(n, coins);
    MS.output();

    return 0;
}