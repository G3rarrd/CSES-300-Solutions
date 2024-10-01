#include <bits/stdc++.h>

using namespace std;
class SegmentTree {

private:
    int *tree;
    int arrSize;

public:
    SegmentTree(int n) {
        arrSize = n;
        tree = new int[n * 2];
    }

    void build(int nums[]) {
        // Shift the nums to the right side of the tree;
        for (int i = arrSize; i < arrSize * 2; i++) {
            tree[i] = nums[i - arrSize];
        }

        for (int i = arrSize - 1; i > 0; i--) {
            tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
        }
    }

    int query(int from, int to)
    {
        from  += arrSize;
        to += arrSize;
        int res = INT_MAX;
        while (from < to) {
            if (from & 1) {
                res = min(res, tree[from++]);
            }
            if (to & 1) {
                res = min(res, tree[--to]);
            }
            from >>= 1;
            to >>= 1;
        }
        return res;
    }
};

void staticRangeMinimumQueries ( int n, int q, int nums[] ) {
    SegmentTree seg(n);
    seg.build(nums);
    
    for (int i = 0; i < q; i++) {
        int from, to;
        cin >> from >> to;
        cout << seg.query(from - 1, to) << endl;
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
   
    int nums[n];

    for (int &x: nums) {
        cin >>x;
    }

    staticRangeMinimumQueries(n, q, nums);
    return 0;
}