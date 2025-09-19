#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const string vowels = "AEIOUY";

bool esvocal(char &c){
    bool e = false;
    for(char i : vowels){
        if(c == i){
            e = true;
        }
    }
    return e;
}

int main(){
    unsigned int n;
    cin >> n;
    vector<string> v(n);
    vector<int> b(n,-1);
    for(int i=0; i < n; i++){
        cin >> v[i];
    }

    for(int i=0; i<n; i++){
        int j = 0;
        
        while (j < 3 && j < v[i].size()){
            if(esvocal(v[i][j])){
                b[i] = j;
            }
            j++;
        }
    }


    for(int i : b){
        cout << i << endl;
    }


    return 0;
}