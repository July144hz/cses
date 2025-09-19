#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
struct point{

    ll x,y;
    point(ll x = 0, ll y = 0) : x(x), y(y) {}
    void print(){
        cout << "("<<x<<';'<<y<<")";
    }

};

int main(){
    int t;
    cin >> t;
    vector<string> v(t);
    for(int i =0 ; i < t ; i++){
        point a,b,c,d;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        b.x = b.x-a.x;
        b.y = b.y-a.y;
        d.x = d.x-c.x;
        d.y = d.y-c.y;
        b.print();
        d.print();
        if(0 == (b.x*d.y) - (b.y*d.x)){
            v[i] = "NO";
        }else{
            v[i] = "YES";
        }
    }
    for(string i : v){
        cout << i << endl;
    }

    return 0;
}