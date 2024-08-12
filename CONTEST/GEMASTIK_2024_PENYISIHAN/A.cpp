#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll A, B, C, D; cin >> A >> B >> C >> D;
    C += B;
    
    if (C == 0) {
        ll ans = (A+D+2) / 3;
        cout << ans << "\n";
    } else {
        if (D-1 >= 3 - A%3 && A%3 != 0) {
            ll k = 3 - A%3;
            A += k;
            D -= k;
        }

        
        ll ans = (A+2)/3 + (C+2)/3 + (D+2)/3;
        // cout << A << " " << B << " " << C << " " << D << "\n";
        cout << ans << "\n";
    }
    




    
    return 0;
}

/*
3 3 3 3

*/