#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll f(string& s, ll len) {
    ll inv = 0;
    for (ll i = 0; i < len; i++) {
        for (ll j = i+1; j < len; j++) {
            if (s[i] > s[j]) inv++;
        }
    }
    return inv;
}

string A[105];
pair<ll, ll> B[105];
bool cmp(pair<ll, ll>& A, pair<ll, ll>& B) {
    if (A.fi == B.fi) {
        return A.se < B.se;
    }
    return A.fi < B.fi;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // string test;
    // while (cin >> test) {
    //     cout << f(test, test.length()) << "\n";
    // }
    // return 0;
    
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll n, m; cin >> n >> m;
        for (ll i = 1; i <= m; i++) {
            cin >> A[i];
            B[i] = {f(A[i], n), i};
        }

        sort(B+1, B+m+1, cmp);
        for (ll i = 1; i <= m; i++) {
            cout << A[B[i].se] << "\n";
        }

        if (t < T) cout << "\n";
    }
    
    return 0;
}