#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct point{

    ll x,y;
    point(ll x=0, ll y=0) : x(x), y(y) {}

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> res(n);
    for(int i =0; i < n; i++){
        point a, b, c;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        b.x = (b.x - a.x);
        b.y = (b.y - a.y);
        c.x = (c.x - a.x);
        c.y = (c.y - a.y);
        ll px = (b.x * c.y) - (b.y * c.x);
        if(px >0){
            res[i] = "LEFT";
        }else if(px < 0){
            res[i] = "RIGHT";
        }
        else{
            res[i] = "TOUCH";
        }
    }

    for (auto i: res){
        cout << i << endl;
    }


    return 0;
}