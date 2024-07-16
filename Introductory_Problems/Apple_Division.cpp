#include <bits/stdc++.h>
using namespace std;


long long minDiff = 1e9;
void appleDivision(long long total, long long a, long long b, long long i, vector<long long>& nums) {
    if (total == a + b) {
        minDiff = min(minDiff, abs(a - b));
        return;
    }

    appleDivision(total, a + nums[i], b, i+1, nums);
    appleDivision(total, a, b + nums[i], i + 1, nums);
}
int main() {
    int n;
    cin >> n;

    long long total = 0;
    vector<long long> nums;
    for (int i = 0; i < n; i++) {
        long long p;
        cin >> p;
        total += p;
        nums.emplace_back(p);
    }

    appleDivision(total, 0, 0, 0, nums);
    cout << minDiff;
    return 0;
}