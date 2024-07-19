#include <bits/stdc++.h>

using namespace std;

// Kadane's Algorithm
long long maximumSubArraySum(int n, vector<long long>& array) {
    long long res = INT_MIN;
    long long curSum = 0;

    for (int i =0; i< n; i++) {
        curSum = max(array[i], curSum + array[i]);
        res = max(res, curSum);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<long long> array;
    for (int i= 0; i < n; i++) {
        long long x;
        cin >> x;
        array.emplace_back(x);
    }
    cout << maximumSubArraySum(n, array);
    return 0;
}