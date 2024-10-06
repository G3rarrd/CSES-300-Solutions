#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class BookShop {
    public :
    ll *memo;
    BookShop () {}

    // Knapsack using a 1D Array
    ll knapsack( ll n, ll totalCost, ll prices[], ll pages[]) {
        memo = new ll[totalCost + 1];
        memset(memo, 0, (totalCost + 1) * sizeof(ll));

        for (int i = 0; i < n; i++) {
            for (int j = totalCost; j >= prices[i]; j--) {
                memo[j] = max(memo[j], pages[i] + memo[j - prices[i]]);
            }
        }

        return memo[totalCost];
    }


};
int main () {
    ll n, x;
    cin >> n >> x;
    ll prices[n], pages[n];

    for (ll i = 0; i < n; i++) {
        cin >> prices[i];
    }

    for (ll i = 0; i < n; i++) {
        cin >> pages[i];
    }

    BookShop BS;
    cout << BS.knapsack(n, x, prices, pages);

    return 0;
}