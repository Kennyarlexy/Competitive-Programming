#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

pair<ll, ll> A[200005];
bool cmp(pair<ll, ll> A, pair<ll, ll> B) {
    return A.first < B.first;
}

int main() {
    fast_io();
    //use ll when possible!
    ll n; cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> A[i].first >> A[i].second;
    }

    sort(A, A + n, cmp);
    ll D = 0;
    ll score = 0;
    for (ll i = 0; i < n; i++) {
        D += A[i].first;
        score += (A[i].second - D);
    }
    cout << score << "\n";

    return 0;
}