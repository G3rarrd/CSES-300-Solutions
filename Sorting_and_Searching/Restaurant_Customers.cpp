#include <bits/stdc++.h>
using namespace std;

// Tip: Line Sweep Algorithm
int restaurantCustomers(int n) {
    map<int, int> lineSweep;

    vector<int> times;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a;
        lineSweep[a] += 1;

        cin >> b ;
        lineSweep[b] -= 1;
    }

    int maxCustomers = 0;
    int currentCustomerCount = 0;

    for (auto it = lineSweep.begin(); it != lineSweep.end(); ++it) {
        currentCustomerCount += it->second; 
        maxCustomers = max(maxCustomers, currentCustomerCount);
    }

    return maxCustomers;
}

int main() {
    int n;
    cin >> n;
    cout << restaurantCustomers(n);
    return 0;
}