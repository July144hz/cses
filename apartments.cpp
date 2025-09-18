#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> desired(n);
    vector<ll> apts(m);
    for(ll i=0; i< n; i++) cin >> desired[i];
    for(ll i=0; i< m; i++) cin >> apts[i];
    sort(desired.begin(),desired.end()); // 45 60 60 80
    sort(apts.begin(),apts.end()); // 30 60 75

    ll i, j, acc;
    i =0;
    j =0;
    acc= 0;
    while(i < n){
        if(apts[j] < desired[i]-k) j++;
        else{
            if(apts[j] <= desired[i]+k){
                acc++;
                j++;
            }
            i++;
        }
        if(j >= m){
            // j=0;
            i++;
        }
        // cout << i << j << endl;
    }
    
    cout << acc << endl;

    return 0;
}