#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string s;
set<string> v;

int main()
{
    cin >> s;
    string e = s;
    /*
    abc
    acb
    bac
    bca
    cab
    cba
    */


    // e = s;
    for (int i = 0; i < s.size(); i++)
    {   
        for (int j = 0; j < s.size(); j++)
        {
            swap(e[i], e[j]);
            v.insert(e);
        }
    }
    cout << v.size() << endl;
    for (auto i : v)
    {
        cout << i << endl;
    }

    return 0;
}