#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
struct point{
    int x,y;
    point(int x=0, int y=0) : x(x) , y(y){}
    point operator-(const point &other) {
        return point(x - other.x, y - other.y);
    }
    ll norma2(){
        return x*x + y*y;
    }
    bool operator==(const point &other){
        return (x==other.x && y==other.y);
    }

    void print(){
        cout << "("<<x<<";"<<y<<")";
    }

    static ll px(const point &a, const point &b){
        return (a.x * b.y) - (a.y * b.x);
    }

};

int main(){
    int n;
    cin >> n;

    vector<point> v(n);
    point lowestY;
    cin >> v[0].x >> v[0].y;
    lowestY = v[0];
    for(int i =1; i<n; i++){
        cin >> v[i].x >> v[i].y;
        if (v[i].y < lowestY.y){
            lowestY = v[i];
        }
    }
    //ayudamemoria
    // ahora ordeno de mayor a menor en eje X a todos los demas puntos y hago el producto cruzado.

    sort(v.begin(),v.end(), [](const point &a, const point &b){
        return a.x > b.x;
    });

    for(point a : v){ // recorro de mas derecha a mas izq
        if(!(a == lowestY)){
            ll dir = point::px(lowestY, a);
            cout << dir << endl;
        }
    }







    return 0;
}