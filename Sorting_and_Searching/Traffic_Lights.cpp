#include <bits/stdc++.h>

using namespace std;
vector<int> trafficLights(int x, int n) {
    vector<int > res;
    set<int> positions_set;
    vector<int> positions_vec;
    positions_set.insert(0);
    positions_set.insert(x);
    for (int i = 0; i < n; i++) {
        int tl;
        cin >> tl;
        positions_set.insert(tl);
        positions_vec.emplace_back(tl);
    }

    int curMaxPassage = 0;
    for (set<int>::iterator it = positions_set.begin(); it != prev(positions_set.end()); ++it) {
        curMaxPassage = max(curMaxPassage, *next(it) - *it );
    }

    res.emplace_back(curMaxPassage);

    while (!positions_vec.empty()) {
        int curVal = positions_vec.back();
        set<int>:: iterator it = positions_set.find(curVal);
        set<int>:: iterator prev_it = it;
        set<int>:: iterator next_it = it;

        if (it != positions_set.begin()) {
            prev_it = prev(it);
        }

        if (next(it) != positions_set.end()) {
            next_it = next(it);
        }

        curMaxPassage = max(curMaxPassage, *next_it - *prev_it);
        res.emplace_back(curMaxPassage);
        positions_vec.pop_back();
        positions_set.erase(curVal);
    }


    return res;
}
int main() {
    int n,x;
    cin >> x;
    cin >> n;
    
    vector<int> res = trafficLights(x,n);
    for (int i = n - 1; i > -1; i--) {
        cout << res[i] << " ";
    }

    return 0;
}