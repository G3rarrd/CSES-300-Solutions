#include <bits/stdc++.h>

// Ordered_set in C++
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;


void josephusProblem(int n, int k) {
    vector<int> res;
    ordered_set children;

    for (int i = 1; i <= n; i++) {
        children.insert(i);
    }

    int start = 0;
    while (!children.empty()) {
        start %= children.size();
        start = (start + k ) % children.size();
        auto it = children.find_by_order(start);

        cout << *it << " ";

        children.erase(*it);
    }
}

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    josephusProblem(n, k);
    return 0;
}

// 2*N