#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

ll A[200005], B[200005], C[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(B, -1, sizeof(B));
    // memset(C, -1, sizeof(C));
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (ll i = 1; i <= n; i++) {
        ll x; cin >> x;
        if (B[x] == -1) B[x] = i;
        C[x] = i;
    }

    ll X = 0;
    for (int i = 1; i <= n; i++) {
        if (B[A[i]] == -1) continue;
        X += max(abs(i - B[A[i]]), abs(i - C[A[i]]));
    }

    cout << X << "\n";
    
    return 0;
}