#include <bits/stdc++.h>
using namespace std;
#define long long ll;

struct book{
    int pr, ps; // precio paginas
    book (int pr=0, int ps =0) : pr(pr), ps(ps){}

};

int main(){
    int n, x;
    cin >> n >> x;
    vector<book> v(n);
    int min_pr =INT32_MIN;
    for(int i =0; i < n; i++){
        cin >> v[i].pr;
        min_pr = min(min_pr, v[i].pr);
    }
    for(int i =0; i < n; i++){
        cin >> v[i].ps;
    }
    /*
    4 10
    4 8 5 3
    5 12 8 1
    */
    
    vector<int> DP(x+1);
    for(int i=0; i<n ;i++){ // i max cant guita
        for(int j =x;j>= v[i].pr; j--){
            DP[j] = max(DP[j], DP[j - v[i].pr] + v[i].ps);
        }
    }

    for(int i: DP){
        cout << i << endl;
    }
    // cout << DP[x] << endl;

}