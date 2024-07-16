#include <bits/stdc++.h> 
using namespace std;
 
struct comp {
    bool operator()(const int& a, const int& b) {
        return a > b;
    }
};
 
int apartments(int n, int m, int k) {
    vector<int> desiredSize;
    vector<int> apartmentsSize;
    int res = 0;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        desiredSize.emplace_back(a);
    }
 
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        apartmentsSize.emplace_back(b);
    }
 
    sort(desiredSize.begin(), desiredSize.end());
 
    sort(apartmentsSize.begin(), apartmentsSize.end());
 
    int iterateA = 0;
    int iterateB = 0;
 
    while (iterateA < n && iterateB < m) {
        if (abs(desiredSize[iterateA] - apartmentsSize[iterateB]) <= k) {
            iterateA++;
            iterateB++;
            res++;
        }
        else {
            if (desiredSize[iterateA] > apartmentsSize[iterateB] ) {
                iterateB++;
            } else {
                iterateA++;
            }
        }
    }
 
    return res;
 
}
int main() {
    int n, m, k;
    cin >> n;
    cin >> m;
    cin >> k;
    cout << apartments(n, m, k);
}