#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll A; cin >> A;
    string B; cin >> B;
    unordered_map<ll, string> hi;
    ll sedangturun = 0;
    ll depth = 1;

    for(ll i = 0; i < B.length(); i++){

        if(depth == A){
            sedangturun = -1;
        }

        hi[depth] += string(1, B[i]);
        else if(depth == 1) sedangturun = 0;


        if(sedangturun==0) depth++;
        else depth--;
        
    }

    for(ll i = A; i >= 1; i--){
        cout << hi[i];
    }
    cout << "\n";
    return 0;
}