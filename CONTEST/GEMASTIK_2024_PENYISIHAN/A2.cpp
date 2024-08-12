#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll A, B, C, D; cin >> A >> B >> C >> D;
    ll ans;
    if (B == 0 && C == 0) {
        ans = (A + D + 2) / 3;
    } else if (B == 0) {
        ans = (A + C + 2) / 3 + (D+2) / 3;
    } else if (C == 0) {
        ans = (A + 2) / 3 + (B + D + 2) / 3;
    } else {
        ans = (A+2) / 3 + (B+C+2) / 3 + (D + 2) / 3;
    }
    
    cout << ans << "\n";
    
    return 0;
}

/*
3 3 3 3

*/