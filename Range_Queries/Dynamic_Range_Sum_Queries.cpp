#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class SegmentTree {
    ll *tree;
    int arrSize;

    public:
    SegmentTree (int n) {
        arrSize = n;
        tree = new ll[n * 2];
    }

    void build(ll nums[]) {
        for(int i = arrSize; i < arrSize * 2; i++) {
            tree[i] = nums[i - arrSize];
        }

        for (int i = arrSize - 1; i > 0; i--){
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        }
    }

    ll query(int from, int to) {
        from += arrSize;
        to += arrSize;
        ll res = 0;
        // l = left, r = right
        for (int l = from, r = to; l < r; l >>= 1 , r >>= 1) {
            if (l & 1) {
                res += tree[l++];
            }
            if (r & 1) {
                res += tree[--r];
            }
        }
        return res;
    }

    void update(int location, int value) {
        location += arrSize;
        tree[location] = value;

        for (int i = location / 2; i > 0; i /= 2) {
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        }
    }
};


void dynamicRangeSumQueries (int n, int q, ll nums[]) {
    SegmentTree seg(n);
    seg.build(nums);

    for (int i = 0; i < q; i++) {
        int operation, a, b;
        cin >> operation >> a >> b;
        if (operation == 1) {
            seg.update(a - 1, b);
            continue;
        } 
        cout << seg.query(a - 1, b) << endl;
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    
    ll nums[n];
    
    for (ll&x : nums) {
        cin >> x;
    }

    dynamicRangeSumQueries (n, q, nums) ;

    return 0;

}