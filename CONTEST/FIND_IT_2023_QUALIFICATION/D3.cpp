#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> res;

void moves(ll k){
    ll x = 0;
    for(ll i = sqrt((double)k); i >= 1; i--){
        if(k%i==0){
            x = i;
            break;
        }
    }
    ll y = k/x;
    res.push_back(x);
    res.push_back(y);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t--){
        res.clear();
        ll x, y; cin >> x >> y;
        moves(x), moves(y);
        ll res2 = res[0] + res[2] + min(res[3], res[1]) - 2;
        ll res1 = res[3] + res[1] + min(res[0], res[2]) - 2 ;
        cout << min(res2, res1) << "\n";
    }
    
    return 0;
}