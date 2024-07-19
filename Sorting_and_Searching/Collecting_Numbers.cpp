#include <bits/stdc++.h>

using namespace std;

struct comp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.first < b.first;
    }
};

int collectingNumbers(int n, vector<pair<int, int>> integers) {
    int rounds = 0;
    int i = 0;
    
    while (i < n) {
        while (integers[i + 1].second > integers[i].second) {
            i++;
        }
        i++;
        rounds++;
    }

    return rounds;
}


int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> integers;
    for (int i = 1; i <= n; i++) {
        int intg;
        cin >> intg;
        integers.emplace_back(make_pair(intg, i));
    }

    sort(integers.begin(), integers.end(), comp());
    cout << collectingNumbers(n, integers);
    return 0;
}