#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> v(10000000);
bitset<10000000> b(0);
vector<ll> coins;

ll solve(ll x){
    if(x < 0) return -1;
    if(b[x]) return v[x]; // 1
    if(x == 0) return 1; // no se todavia
    if(x < coins[0]){
        b[x]=1;
        v[x]=-1;
        return -1;
    };
    ll d= coins[0]; // 1000000
    ll acum = 0;
    if(coins.size() == 1){
        acum = solve(x-d);
        if(acum != -1){
            acum +=1;
        }
    }

    // 1 5 7
    // 3
    for(int i = 1; i<coins.size(); i++){
        ll a = solve(x-d); 
        ll b = solve(x-coins[i]); 
        // cout << "COMPARO " << a << " " << b << " X = " << x << endl;
        if(a == -1 || b == -1){
            d = max(a,b);
            // cout << d << " ES EL MAX ENTRE " << a << " " << b << endl;
        }else{
            d = min(a,b);
            // cout << d << " ES EL MIN ENTRE " << a << " " << b << endl;
        }
        acum +=d;
    }
    // cout << "SALE "<< acum << endl;
    if(d == -1){
        v[x] = -1;
        b[x] = 1;
        return -1;
    }
    
    
    v[x] = acum;
    b[x] = 1;

    return acum;
}

int main(){

    ll n, x;
    cin >> n >> x;
    for(int i=0; i<n; i++){
        ll e;
        cin >> e;
        b[e] = 1;
        v[e] = 1;
        coins.push_back(e);
    }
    sort(coins.begin(),coins.end());

    cout << solve(x) << endl;



    return 0;
}