#include<bits/stdc++.h>
using namespace std;

long twoKnights(long k) {
    long totalWays = ((k*k) * (k*k - 1)) / 2; // You can also use k combination 2 to get this value

    long totalAttackingWays = 2*(k - 1) * 2*(k - 2);

    return totalWays - totalAttackingWays; 
}

int main(){
    int n;
    cin >> n;
    cout << 0 << endl;
    for (int i = 2 ; i <= n; i++) {
        cout << twoKnights(i) << endl;
    }
    return 0;
}