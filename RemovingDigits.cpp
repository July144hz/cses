#include <bits/stdc++.h>

using namespace std;



int main(){

    int n;
    cin >> n;
    vector<int> DP(n+1);
    DP[0] = 0;
    for(int i =1; i <= n; i++){
        if(i < 10){
            DP[i] = 1;
        }else{
            // get last number
            string is = to_string(i);
            int m =-1;
            for(int j = is.size()-1; j>= 0; j--){
                m = max(m, is[j] - '0');
            }
            // cout << i << " " << i - (is[j] - '0') << endl;
            DP[i] = DP[i - m] + 1;

        }
    }

    cout << DP[n] << endl;


    /*
    167
    160
    154
    150
    145
    140
    136
    130
    127
    120
    118
    110
    109
    1
    */

    return 0;
}