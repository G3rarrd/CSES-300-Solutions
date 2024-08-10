#include <bits/stdc++.h>

using namespace std;

struct comp {
    bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) const {
        if (get<1>(a) == get<1>(b)) return get<2>(a) > get<2>(b);
        return get<1>(a) > get<1>(b);
    }
};

void roomAllocation(int n) {
    set<tuple<int, int, int>> customers;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start;
        cin >> end;
        customers.insert(make_tuple(start, end, i));
    }

    vector<int> res(n, 0);

    int maxRoom = 0; 
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, comp> minHeap;
    int count = 0;
    for(auto it = customers.begin(); it != customers.end(); ++it) {
        count++;

        if(minHeap.empty()) {
            minHeap.push(*it); 
            res[get<2>(*it)] = count;
            continue;
        }

        tuple<int, int, int> tp = minHeap.top();
        
        if (get<0>(*it) > get<1>(tp)) {
            res[get<2>(*it)] = res[get<2>(tp)];
            minHeap.pop();
            count--;
        }
        else {
            res[get<2>(*it)] = count;
        }
        minHeap.push(*it);
        
        maxRoom = max(maxRoom, count);
    }

    cout << maxRoom << endl;

    for (int i =0; i< n; i++) {
        cout << res[i] << ' ';
    }
} 

int main() {
    int n;
    cin >> n;
    roomAllocation(n);
    return 0;
}