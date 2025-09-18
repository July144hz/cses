#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin >> n >> x;
    vector<int> DP(x+1,0);
    vector<int> coins(n);
    for(int i =0 ; i< n; i++){
        cin >> coins[i];
    }

    DP[0] = 1;
    for(int i=1; i<= x;i++){
        for(int c : coins){
            if(i-c >=0){
                DP[i] += DP[i-c];
                if(DP[i] >= MOD){
                    DP[i] -= MOD;
                }
            }
        }
    }
    cout << DP[x] << endl;


    return 0;
}