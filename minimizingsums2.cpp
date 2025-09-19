#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> v(1000001);
bitset<1000001> b;
vector<ll> coins;

ll solve(ll x){ // 1 5 7 11
    if(x < 0) return -1;
    if(x == 0) return 1;
    if(b[x]) return v[x];
    ll a = solve(x-coins[0]); 
    for(int i =1; i< (ll) coins.size(); i++){
        ll b =solve(x-coins[i]);
        if(a != -1 && b != -1) a = min(a,b);
        else a = max(a,b);
    }
    v[x] = a == -1 ? a : a+1;
    b[x] = 1;
    return a == -1 ? a : a+1;
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, x;
    cin >> n >> x;
    for(ll i =0 ;i < n; i++){
        ll e;
        cin >> e;
        coins.push_back(e);
        v[e] =1;
        b[e] =1;
    }
    sort(coins.begin(),coins.end());

    
    for(ll i=0; i <= x; i ++){
        ll e = solve(i);
        v[i] = e;
        b[i] = 1;
    }

    cout << v[x] << endl;

    return 0;
}