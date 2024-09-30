#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void staticRangeSumQueries (int n, vector<pair<int , int>> queries, vector<ll> nums) {
    for (int i = 1; i<n;i++) {
        nums[i] += nums[i - 1];
    }
    
    for (pair<int, int> p : queries) {
        ll leftVal = (p.first == 1) ? 0 : nums[p.first - 2];
        ll rightVal = nums[p.second - 1];
        ll ans = rightVal - leftVal;
        cout << ans << endl;
    }

}
int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> nums(n);

    for (ll& x : nums) {
        cin >> x;
    }

    vector<pair<int , int>> queries(q, make_pair(0, 0));

    for (pair<int, int>& p : queries) {
        cin >> p.first >> p.second;
    }

    staticRangeSumQueries (n, queries, nums);
    return 0;
}