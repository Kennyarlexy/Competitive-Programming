#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

bool f(ll x) {
    cout << "? " << x << " " << x << endl;
    ll y; cin >> y;

    return y > x*x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);    
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll x = 999;
        for (ll step = 512; step > 0; step /= 2) {
            if (x - step > 1 && f(x-step)) x-= step;    
        }
        
        cout << "! " << x << endl;
    }
    
    return 0; 
}