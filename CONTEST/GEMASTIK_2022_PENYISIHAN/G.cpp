#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

map<ll, ll> cnt;
ll A[200005];

int main() {
    fast_io();
    //use ll when possible!
    ll N; cin >> N;
    for (ll i = 1; i <= N; i++) {
        ll a; cin >> a;
        cnt[a]++;
    }

    
    for (ll k = 1; k <= N; k++) {
        A[k] = cnt[k];
    }
    
    for (ll k = N-1; k >= 1; k--) {
        A[k] += A[k+1];
    }

    for (ll i = 1; i <= N; i++) {
        cout << N - A[i] << " ";
    }
    cout << "\n";

    return 0;
}