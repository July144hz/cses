#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> v(1000001);
bitset<1000001> b;

vector<ll> coins;

ll solve(ll x){
    if(x < 0) return 0;
    if(x == 0) return 1;
    if(b[x]) return v[x];

    ll a = coins[0];


}

int main(){
    ll n,x;
    cin >> n >> x;
    for(int i=0; i< n;i++){
        ll e;
        cin >> e;
        coins.push_back(e);
    }
    sort(coins.begin(),coins.end());

    for(int i =0; i < 1000001; i++){
        solve(i);
    }



    return 0;
}