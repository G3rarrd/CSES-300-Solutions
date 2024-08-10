#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 


struct comp
{
    int x, y, in;
    bool operator<(const comp &other) const
    {
        if (x == other.x){
            return y > other.y;
        }
        return x < other.x;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<comp> ranges(n);
    vector<int> contains(n, 0);
    vector<int> contained(n, 0);
    ordered_set prevEnds; 
    
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x;
        cin >> y;
        ranges[i].x = x;
        ranges[i].y = y;
        ranges[i].in = i;
    }

    sort(ranges.begin(), ranges.end());

    // Contains
    for (int i = n - 1; i >= 0; i--) {  
        comp r = ranges[i]; 
        // Pairs is used to deal with duplicate values.
        // The second element (n) is just a large number to ensure that 
        // we are counting all intervals that end before or exactly at r.y.
        contains[r.in] = prevEnds.order_of_key({r.y , n});
        prevEnds.insert({r.y, r.in});
    }

    prevEnds.clear();
    
    // Contained
    for (int i = 0; i < n; i++) {
        comp r = ranges[i];
        contained[r.in] = prevEnds.size() - prevEnds.order_of_key({r.y, -1});
        prevEnds.insert({r.y, r.in});
    }

    for (const auto& x : contains) {
        cout << x << ' ';
    }

    cout << endl;

    for (const auto& x : contained) {
        cout << x << ' ';
    }


    
    return 0;
}

