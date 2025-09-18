#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node{
    ll data;
    ll a,b,m;
    node* der;
    node* izq;
};

node * appendtree(vector<ll> &v, ll a, ll b){
    node* e = new node();
    e->a=a;
    e->b=b;
    if(a == b){
        e->data = v[a];
        e->der = nullptr;
        e->izq = nullptr;
        e->m = a;
        return e;
    }
    e->data = v[a];
    for(int i = a+1; i <= b; i++){
        if(v[i] < e->data){
            e->data= v[i];
        }
    }
    ll m = (a+b)/2;
    e->m = m;
    e->izq = appendtree(v,a,m);
    e->der = appendtree(v,m+1,b);
    return e;
}

void show(node * &e){
    if(e == nullptr) return;
    show(e->izq);
    show(e->der);
}

int hallarmin(const vector<ll> &v, node * & e,ll a, ll b){
    if(e->a == a && e->b == b){
        return e->data;
    }
    if(a <= e->m && b <= e->m){
        return hallarmin(v, e->izq, a, b);
    }
    if(a<= e->m && b > e->m){
        return min(hallarmin(v,e->izq,a,e->m), hallarmin(v,e->der, e->m+1, b));
    }
    return hallarmin(v,e->der,a,b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,q;
    cin>>n>>q;

    vector<ll> v(n);
    ll e;
    cin >> e;
    v[0] = e;
    pair<ll,ll> mi(e,0);
    for(int i =1; i< n; i++){
        cin  >> v[i];
        if(v[i] < mi.first){
            mi = {v[i],i};
        }
    }
    node* raiz = new node();
    raiz->a = 0;
    raiz->b = v.size()-1;
    raiz->data = mi.first;
    ll m = (v.size()-1)/2;
    raiz->m = m;
    raiz->izq = appendtree(v,0, m);
    raiz->der = appendtree(v,m+1,v.size()-1);
    vector<pair<ll,ll>> qs(q);

    for(int i =0; i< q; i++){
        ll a,b;
        cin >> a >> b;
        qs[i] = pair<ll,ll> (a-1,b-1);
    }

    for(int i =0; i< q; i++){
        ll a,b;
        a= qs[i].first;
        b= qs[i].second;
        cout << hallarmin(v,raiz,a,b) << endl;
    }

    


    
    return 0;
}