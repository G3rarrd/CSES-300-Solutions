#include <bits/stdc++.h>
using namespace std;

// To display in an alphabetical order;
set<string> permutations;

void permute(string s, int l, int n) {
    if (l >= n) {
        permutations.insert(s);
        return;
    }

    for (int i = l; i <n; i++){
        swap(s[i], s[l]);
        permute(s, l + 1, n);
        swap(s[i], s[l]);
    }
}

int main () {
    string s;
    cin >> s;
    int n = s.size();
    permute(s, 0, n);
    cout << permutations.size() << '\n';

    for (const string& p : permutations) {
        cout << p << endl;
    }

    return 0;
}

