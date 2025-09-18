#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point{
    ll x, y;
    point(ll x=0 , ll y=0) : x(x), y(y){}


};

int main(){

    ll n;
    cin >> n;
    vector<point> v(n);
    for(ll i =0; i<n; i++){
        ll x,y;
        cin>> x>>y;
        v[i].x = x;
        v[i].y = y;
    }
    

    ll acc =0;
    for(ll i=0; i<n; i++){
        ll j = (i+1)%n;
        acc+= (v[i].x * v[j].y) -( v[i].y * v[j].x);

    }
    cout << abs(acc) << endl;


    return 0;
}