#include <bits/stdc++.h>
using namespace std;

// convert number to binary 
string intToBin(int num, int n) {
    string bin(n, '0');
    int i = 0;
    while (num > 0) {
        bin[i] = '0' + (num & 1);
        num >>= 1;
        i++;
    }
    reverse(bin.begin(), bin.end());
    return bin;
}

// Formula for graycode num (num ^ num >> 1)
string getGraycode(int num, int n) {
    return intToBin((num)^(num>>1), n);
}

int main() {
    int n;
    cin >> n;
    
    for (int i =0; i < pow(2, n); i++) {
        cout << getGraycode(i, n) << endl;
    }
}