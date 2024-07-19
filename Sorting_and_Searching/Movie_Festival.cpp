#include <bits/stdc++.h>
using namespace std;

struct comp {
    bool operator()(const pair<int, int>& a,const pair<int, int>& b) const {
        return a.second < b.second;
    }
};

int movieFestival(vector<pair<int, int>> timeFrames, int n) {
    pair<int , int> curMovie = timeFrames[0];
    int res = 1;
    int i = 1;
    
    while (i < n) {
        if (timeFrames[i].first >= curMovie.second) {
            curMovie = timeFrames[i];
            res++;
        }
        i++;
    }   
    return res;
}

int main() {

    int n;
    cin >> n;
    vector<pair<int, int>> timeFrames;

    for (int i = 0; i < n; i++) {
        int a;
        int b;
        cin >> a, cin >> b;
        timeFrames.emplace_back(make_pair(a, b));
    }
    
    // Sort according to the end times
    sort(timeFrames.begin(), timeFrames.end(), comp());
    cout << movieFestival(timeFrames, n);
    return 0;
}