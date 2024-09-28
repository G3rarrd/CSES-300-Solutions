#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


ll subarrayDistinctValues(int n, int k, vector<int> nums) {
    ll res = 0;
    map<int, int> mp;
    int i = 0;
    int j = 0;
    while (i < n) {
        mp[nums[i]]++;
        while (mp.size() > k) {
            mp[nums[j]]--;
            if (mp[nums[j]] == 0) {
                mp.erase(nums[j]);
            }
            j++;
        }
        i++;
        res += i - j;
    }
    
    return res;
}
int main() {
    int n;
    int k;
    cin >> n;
    cin >> k;
    
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.emplace_back(x);
    }

    cout << subarrayDistinctValues(n, k, nums);

}