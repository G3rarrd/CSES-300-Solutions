#include <bits/stdc++.h>

using namespace std;
int subArraySums(vector<int> nums, int n, int target) {
    int j = 0;
    int curSum = 0;
    int count = 0;
    for (int i =0 ; i < n; i ++) {
        curSum += nums[i];
        while (curSum > target && j < i) {
            curSum -= nums[j];
            j++;
        }

        if (curSum == target) {
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    int target;
    cin >> n;
    cin >> target;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.emplace_back(x);
    }

    int res = subArraySums(nums, n, target);
    cout << res;
}