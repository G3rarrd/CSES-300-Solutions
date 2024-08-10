#include <bits/stdc++.h>
using namespace std;

vector<int>josephusProblem( int n) {
    vector<int> res;
    queue<int> children;
    for (int i = 1; i <= n; i++) {
        children.push(i);
    }

    int i = 1;
    while (!children.empty()) {
        if (!(i % 2)) {
            res.emplace_back(children.front());
        } else {
            children.emplace(children.front());
        }
        children.pop();
        i++;
    }
    
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> res = josephusProblem(n); 
    for (int i : res) {
        cout << i << " ";
    }
    return 0;
}

// Time Complexity = 2 * N