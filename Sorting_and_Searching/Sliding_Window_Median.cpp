#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution
{
private:
    multiset<ll> maxSet;
    multiset<ll> minSet;

public:
    void rebalance() {
        if (maxSet.size() > minSet.size() + 1) {
            minSet.insert(*maxSet.rbegin());
            maxSet.erase(--maxSet.end());

        } else if (minSet.size() > maxSet.size()) {
            maxSet.insert(*minSet.begin());
            minSet.erase(minSet.begin());
        }
    }

    void addNum(ll num) {
        if (maxSet.empty() || num <= *maxSet.rbegin()) {
            maxSet.insert(num);

        } else {
            minSet.insert(num);
        }

        rebalance();
    }

    void delNum (ll num) {
        auto findMaxNum = maxSet.find(num);
        if (findMaxNum != maxSet.end()) {
            maxSet.erase(findMaxNum);

        } else {
            minSet.erase(minSet.find(num));
        }

        rebalance();
    }

    ll getMedian(ll k) {
        return *maxSet.rbegin();  
    }

    void slidingWindowMedian(ll n, ll k, vector<ll> nums) {
        // Initialize the window
        for (ll i = 0; i < k; i++) {
            addNum(nums[i]);
        }

        cout << getMedian(k) << ' ';

        for (ll i = k; i < n; i++) {
            delNum(nums[i - k]);
            addNum(nums[i]);
            cout << getMedian(k) << ' ';
        }
    }
};


int main()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> nums(n);
    for (ll &x : nums)
    {
        cin >> x;
    }
    Solution solution;
    solution.slidingWindowMedian(n, k, nums);
    return 0;
}