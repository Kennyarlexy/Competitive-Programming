#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n; cin >> n;
    ll sum = 0;

    if((ll)sqrt(n) == sqrt(n)) sum += sqrt(n)-1;
    
    for(ll i = 2; i*i < n; i++){
        ll hi = i*i;
        ll x = sqrt((double) n/hi);
        double y = sqrt((double) n/hi);

        if(n%hi==0 && x!=y){
            sum += i-1;
        }
    }
    cout << sum << "\n";

    return 0;
}