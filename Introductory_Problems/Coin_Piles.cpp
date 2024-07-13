#include <bits/stdc++.h>
using namespace std;

string possible(int a, int b) {
    // Simplify Simultaneous equation of (A = 2x + y) and (B = 2y + x);
    // Make sure the (2b - a) and (2a -b) is grater than or equal to zero.

    if (((2 * a) - b)% 3 == 0 && ((2 * b) - a) % 3 == 0 && ((2*b ) - a >= 0) && (2 * a) - b >= 0) {
        return "YES";
    }
    
    return "NO";
}

int main(){
    int t; 
    cin >> t;

    for (int i = 0; i < t; i++){
        int a, b;
        cin >> a, cin >> b;
        cout << possible(a, b);
        cout << endl;
    }

    return 0;
}