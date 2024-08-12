#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second 
using namespace std;

ll query(pair<ll, ll> P) {
    cout << "? " << P.fi << " " << P.se << endl;
    ll d; cin >> d; 
    return d;
}

void answer(pair<ll, ll> P) {
    cout << "! " << P.fi << " " << P.se << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n, m; cin >> n >> m;
        pair<ll, ll> A = {1, 1};
        ll d = query(A);
        if (d == 0) {
            answer(A);
            continue;
        }

        pair<ll, ll> B = {1 + max(0LL, d-(m-1)), 1 + min(m-1, d)};
        ll mn = min(n-B.fi, B.se-1);
        pair<ll, ll> D = {B.fi + mn, B.se - mn};
        pair<ll, ll> Q[] = {B, D};
        
        vector<ll> R;
        for (int i = 0; i < 2; i++) {
            R.push_back(query(Q[i]));
        }

        pair<ll, ll> C = {B.fi + R[0]/2, B.se - R[0]/2};
        d = query(C);

        if (d == 0) {
            answer(C);
        } else {
            pair<ll, ll> E = {D.fi - R[1]/2, D.se + R[1]/2};
            answer(E);
        }
    }
    
    return 0;
}