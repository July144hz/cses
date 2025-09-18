#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<bool> b(1000001, false);
vector<ll> v(1000001, 0);

ll solve(ll x){
    if(x < 0) return 0;
    if(x == 0) return 1;
    if(b[x]) return v[x];

    v[x] = (solve(x-1) + solve(x-2) + solve(x-3) + solve(x-4) + solve(x-5) + solve(x-6))%(1000000007);
    b[x] = true;

    return v[x];
}

int main(){
    ll e;
    cin >>e;

    // solve(25000);

    cout << solve(e) << endl;
    

    return 0;
}
/*
1. 1
2.
1 1
2

3.
1 1 1
1 2
2 1
3

4.
1 1 1 1
1 1 2
1 2 1
2 1 1
2 2
3 1
1 3
4

*/