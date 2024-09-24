#include <bits/stdc++.h>
using namespace std;

long long subArraySums(vector<long long> nums, int n, long long target){
    map<long long, long long> mp;
    long long count = 0;
    long long curSum = 0;
    mp[0]++;
    for (int i = 0; i< n; i++) {
        curSum += nums[i];
        long long k =  curSum - target ;
        
        if (mp.find(k) != mp.end()) {
            count += mp[k];    
        }
        
        mp[curSum]++;
    }

    return count;
}



int main () {
    long long n;
    long long target;
    
    cin >> n;
    cin >> target;
    
    vector<long long> nums;

    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        nums.emplace_back(x);
    }

    cout << subArraySums(nums, n, target) ; 
}