#include <bits/stdc++.h>
using namespace std;

struct myComp
{
    bool operator()(const pair<char, int> a, const pair<char, int> b) const
    {
        return a.second < b.second;
    }
};

string palindromeReorder(string s)
{
    int oddCount = 0;
    int n = s.size();
    unordered_map<char, int> freq;

    for (char c : s)
    {
        freq[c]++;
        oddCount += freq[c] % 2 ? 1 : -1;
    }

    if (oddCount > 1)
    {
        return "NO SOLUTION";
    }

    priority_queue<pair<char, int>, vector<pair<char, int>>, myComp> maxHeap;

    for (const auto &p : freq)
    {
        maxHeap.push(p);
    }


    int i = 0;
    while (!maxHeap.empty())
    {
        pair<char, int> tp1 = maxHeap.top();
        maxHeap.pop();

        if (tp1.second > 1)
        {
            s[i] = tp1.first;
            s[n - i - 1] = tp1.first;
            tp1.second -= 2;
        }

        else if (tp1.second == 1)
        {
            s[i] = tp1.first;
            tp1.second--;
        }

        i++;
        if (tp1.second > 0) maxHeap.push(tp1);

    }
    return s;
}

int main()
{
    string s;
    cin >> s;
    cout << palindromeReorder(s);
    return 0;
}