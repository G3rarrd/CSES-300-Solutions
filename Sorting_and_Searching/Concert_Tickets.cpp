#include <bits/stdc++.h>
using namespace std;

vector<int> concertTickets(int n, int m) {
    map<int, int> tickets;
    vector<int> customers;

    for (int i = 0 ; i < n; i++) {
        int t;
        cin >> t;
        tickets[t]++;
    }

    vector<int> res;

    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        auto it = tickets.lower_bound(c);

        if(tickets.size() == 0) {
            res.emplace_back(-1);
            continue;
        }

        if (it->first > c || it == tickets.end()) {
            if (it == tickets.begin()) {
                res.emplace_back(-1);
                continue;
            }
            it--;
        } 

        res.emplace_back(it->first);
        it->second--;

        if (it->second == 0) {
            tickets.erase(it);
        }
    }
    return res;
} 


int main() {
    int n, m;
    cin >> n;
    cin >> m;
    vector<int> res = concertTickets(n, m);

    for (int ans : res) {
        cout << ans << endl;
    }

    return 0;
}