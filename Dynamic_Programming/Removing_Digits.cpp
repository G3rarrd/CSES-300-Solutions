#include <bits/stdc++.h>

using namespace std;

class RemovingDigits {
    public :
    int *memo;
    RemovingDigits(int n) {
        memo = new int[n + 1];
        memset(memo, -1, (n + 1) * sizeof(int));
        memo[n] = 0;
    }

    int solve (int n) {
        for (int i = n; i >= 0; i--) {
            int x = i;
            if (memo[i] == -1) continue;
            while (x > 0) {
                int d = x % 10;
                if (i - d >= 0 && (memo[i - d] == -1 || memo[i - d] > memo[i] + 1) ) {
                    memo[i - d] = memo[i] + 1;
                }
                x /= 10;
            }
        }
        return memo[0];
    }
};

int main() {
    int n;
    cin >> n;
    RemovingDigits RD(n);
    cout << RD.solve(n);
    
    return 0;
}