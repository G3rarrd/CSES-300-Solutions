#include <bits/stdc++.h>
using namespace std;

// Hint: Use this formula (n^2) - (n - 1) to help
int main() {
    long long t;
    cin >> t;
    vector<long long> answers;
    for (long long i = 0; i < t; i++) {
        long long y, x;
        
        cin >> y, cin >> x;

        long long maximum = max(y, x);
        long long start = ((maximum*maximum) - (maximum - 1));
        
        if (x == y) {
            answers.emplace_back(start);
        }

        else if (y < x) {
            start += (x%2)? (x - y)  : -(x - y );
            answers.emplace_back(start);
        }
        else {
            start += (y%2) ?-(y - x) : y - x ;
            answers.emplace_back(start);
        }
        cout << start;
        cout << endl;
    }

    
    return 0;
}

// MIstake: Forgot long long