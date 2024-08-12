#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll sum_genap = 0;
        ll sum_ganjil = 0;
        for(ll i = 0; i < n; i++){
            ll temp; cin >> temp;
            if(i%2==0) sum_ganjil += temp;
            else sum_genap += temp;
        }

        bool x = (n%2==0) && (sum_genap >= sum_ganjil);
        bool y = (n%2!=0);

        if(x||y) cout << "YA\n";
        else cout << "TIDAK\n";
    }
    return 0;
}