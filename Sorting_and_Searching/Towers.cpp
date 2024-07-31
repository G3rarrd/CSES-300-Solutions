#include <bits/stdc++.h>

using namespace std;

int towers(int n) {
    vector<int> cubes;
    // For this variation of binary search, lo + 1 is needed.
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        int lo = -1;
        int hi = cubes.size();

        while (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            if (cubes[mid] <= k) {
                lo = mid;
                continue;
            }
            hi = mid;
        }

        if (lo + 1  == cubes.size()) {
            cubes.emplace_back(k);
            continue;
        } 

        cubes[lo + 1] = k;
    }

    return cubes.size();
}

int main() {
    int n;
    cin >> n;
    cout << towers(n);
    return 0;
}