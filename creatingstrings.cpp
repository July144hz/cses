#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string s;
set<string> v;

int main()
{
    cin >> s;

    string e = s;
    v.insert(s);
    next_permutation(e.begin(), e.end());
    while (e != s)
    {
        v.insert(e);
        next_permutation(e.begin(), e.end());
    }

    cout << v.size() << endl;
    for (auto i : v)
    {
        cout << i << endl;
    }

    return 0;
}