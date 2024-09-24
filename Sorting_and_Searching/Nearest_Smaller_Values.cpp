#include <bits/stdc++.h>
using namespace std;
// Monotonic Stack
vector<int> nearestSmallerValues (vector<int>&nums, int n) {
    stack<int> st;
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] >= nums[i] ) {
            st.pop();
        }
        if (!st.empty()) {
            res[i] = st.top() + 1;
        }
        st.push(i);
    }

    return res; 
} 

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.emplace_back(x);
    }

    for (int x : nearestSmallerValues(nums, n)) {
        cout << x << ' ';
    }

    
}