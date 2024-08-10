#include <bits/stdc++.h>

using namespace std;

int playlist(vector<int> songs, int n) {
    int res = 0;
    map<int, int> songPositions;
    int startPos = -1;
    for (int i = 0; i < n; i++) {
        if (songPositions.find(songs[i])!= songPositions.end()) {
            startPos = max(startPos, songPositions[songs[i]]); 
        }
        songPositions[songs[i]] = i;
        res = max(res, (i - startPos));
    }    
    return res;
}

int main () {
    int n;
    cin >> n;
    vector<int> songs;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        songs.emplace_back(k);
    }

    cout << playlist(songs, n);
}