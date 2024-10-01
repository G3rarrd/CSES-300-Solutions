#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
    pair<int, int> *tree;
    int arrSize;
    public :

    SegmentTree(int n) {
        arrSize = n;
        tree = new pair<int, int>[n * 2];
    }

    pair<int, int> combine(pair<int, int> nodeA, pair<int, int> nodeB) {
        if(nodeA.first > nodeB.first ) return nodeB;

        if (nodeA.first < nodeB.first) return nodeA;

        return make_pair(nodeA.first, nodeA.second + nodeB.second);
    }

    void build(int nums[]) {
        for (int i = arrSize; i < arrSize * 2; i++) {
            tree[i] = make_pair(nums[i - arrSize], 1);
        }

        for (int i = arrSize - 1; i > 0; i--) {
            tree[i] = combine(tree[i << 1], tree[i << 1 | 1]);
        }
    }

    void update(int location, int value) {
        location += arrSize;
        tree[location] = {value, 1};
        for (int i = location / 2 ; i > 0; i /= 2) {
            tree[i] = combine(tree[i << 1], tree[i << 1 | 1]);
        }
    }

    pair<int, int> query(int from, int to) {
        from += arrSize;
        to += arrSize;
        pair<int, int> res = make_pair(INT_MAX, 1);
        while (from < to) {
            if (from & 1) {
                res = combine(tree[from++], res);
            }

            if (to & 1) {
                res = combine(tree[--to], res);
            }
            from >>= 1;
            to >>= 1;
        }
        return res;
    }


};

void numberOfMinimumOnASegment(int n, int q, int nums[]) {
    SegmentTree seg(n);
    seg.build(nums);
    for (int i = 0; i < q; i++) {
        int operation , a, b;
        cin >> operation >> a >> b;
        if (operation == 1) {
            seg.update(a, b);
            continue;
        }
        auto [least, count] = seg.query(a, b); 
        cout << least << ' ' << count << endl;
    }
}

int main () {
    int n, q;
    cin >> n >> q;

    int nums[n];

    for (int &x : nums) {
        cin >> x;
    }

    numberOfMinimumOnASegment(n, q, nums); 

    return 0;
}