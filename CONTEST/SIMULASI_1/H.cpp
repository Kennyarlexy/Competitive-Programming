#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

pair<string, ll> A[200005];
bool cmp(pair<string, ll> A, pair<string, ll> B) {
    return A.second < B.second;
}

int main() {
    fast_io();
    //use ll when possible!
    ll n; cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A, A + n, cmp);

    cout << A[n/2].first << "\n";

    return 0;
}