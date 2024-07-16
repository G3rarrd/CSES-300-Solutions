// Bit Manipulation Method
#include <bits/stdc++.h>
using namespace std;
 
int main () {
    int n;
    cin >> n;
    int c = 0;
    
    for (int i = 0; i < n -1; i++) {
        int x;
        cin >> x;
        c ^= x;
    }
 
    for (int i = 1; i <= n; i++) {
        c ^= i;
    }
 
    cout << c;

    return 0;
}