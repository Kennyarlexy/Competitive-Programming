#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second

using namespace std;

bool sieve[2000005];

void construct_sieve(ll sz) {
    sieve[0] = sieve[1] = true;
    
    for (ll i = 2; i*i <= sz; i++) {
        if (sieve[i]) continue;
        for (ll j = i*i; j <= sz; j += i) {
            sieve[j] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, X; cin >> N >> X;
    construct_sieve(N);

    ll mx = 0;
    vector<int> A; A.reserve(4*N + 5);
    for (int i = 1; i+2 <= N; i++) {
        if (sieve[i] || sieve[i+2]) continue;

        ll a = i, b = i+2;
        A.push_back(a);
        A.push_back(a+1);
        A.push_back(b);
        A.push_back(a+b);
        mx = max(mx, a+b);
    }

    ll d = (N < 50) ? 12 : 50;
    ll k = mx / d;


    set<ll> S;
    for (auto a : A) {
        if (a >= X && (a-X) % d == 0 && a-X <= k*d) S.insert((a-X) / d);
        if ((a+X) % d == 0 && a+X <= k*d) S.insert((a+X) / d);
    }
    ll ans = S.size();
    cout << ans << "\n";
    
    return 0;
}
