#include <bits/stdc++.h>

using namespace std;

struct comp{
    bool operator()(const pair<int , int>& a, const pair<int, int>& b) const {
        return a.first < b.first;
    } 
};

// Two pointer Solution
void sum_of_two_values(vector<pair<int, int >> vals, int x, int n) {
    int hi = n - 1;
    int lo = 0;
    while (lo < hi) {
        if (vals[hi].first + vals[lo].first == x) {
            cout << vals[lo].second  << " " <<   vals[hi].second ;
            return;
        }

        if (vals[hi].first + vals[lo].first > x) {
            hi--;

        } else {
            lo++;
        }
    }

    cout << "IMPOSSIBLE";
    return; 
}

int main() {
    vector<pair<int, int>> vals;
    int n;
    cin >> n;
    int x;
    cin >> x;

    for (int i =1 ;i <= n; i++) {
        int v;
        cin >> v;
        vals.emplace_back(make_pair(v, i));  
    }

    sort(vals.begin(), vals.end(), comp());

    sum_of_two_values(vals, x, n);

    return 0;
}