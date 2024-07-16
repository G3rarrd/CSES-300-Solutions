#include <bits/stdc++.h>
using namespace std;
 
// Sets Method
int distinctNumbersSet() {
    int n;
    cin >> n;
    // Use an ordered_set instead of an unordered_set(unordered_set has a worst case complexity of O(N) when inserting compared to O(logN))  
    set<int> nums; 
    for (int i =0; i < n; i++) {
        int x;
        cin >> x; 
        nums.insert(x);
    }    
    return nums.size();
}
// Time Complexity: O(NlogN)
 
 
// Sorting Method
int distinctNumbersSort() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.emplace_back(x);
    }
 
    sort(nums.begin(), nums.end());
    
    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
        ans += (nums[i] != nums[i + 1]);
    }
 
    return ans;
} 
 
int main() {
    cout << distinctNumbersSort();
}
// Time Complexity: O(NlogN)