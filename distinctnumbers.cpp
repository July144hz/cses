#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll i =0 ; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());

    ll a =1;
    for(int i =1; i < n; i ++){
        if(v[i] != v[i-1]) a++;
    }

    cout << a << endl;

    return 0;
}