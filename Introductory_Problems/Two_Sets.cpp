#include <bits/stdc++.h>
using namespace std;

// Note: Use long long in this problem
int main(){
    long long n;
    cin >> n;
    // Formula for summing sequence
    long long gauss = (n*(n + 1)) / 2;

    // Cannot be divided into 2
    if (gauss%2 == 1) {
        cout << "NO";
        return 0;
    }

    long long gaussHalf = gauss / 2;

    vector<int> firstSet ;
    vector<int> secondSet;

    cout << "YES" << endl;
    while (n > 0) {
        if (gaussHalf - n >= 0 ) {
            firstSet.emplace_back(n);
            gaussHalf -= n;
        } else {
            secondSet.emplace_back(n);
        }
        n--;
    }

    int firstSetSize = firstSet.size();
    int secondSetSize = secondSet.size();

    cout << firstSetSize << endl;

    for (int i =0; i < firstSetSize; i++) {
        cout << firstSet[i] << ' ';
    }
    cout << endl;

    cout << secondSetSize << endl;
    for (int i =0; i < secondSetSize; i++) {
        cout << secondSet[i] << ' ';
    } 
    cout << endl;

    
    return 0;
}
