#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

pair<ll, ll> A[1000005];

int main() {
    fast_io();
    //use ll when possible!
    ll N, M; cin >> N >> M;

    ll cnt = 0;
    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= M; j++) {
            char ch; cin >> ch;
            if (ch == 'X') {
                A[cnt++] = {i, j};
            }
        }
    }

    cout << cnt << "\n";
    for (ll i = 0; i < cnt; i++) {
        cout << A[i].first << " " << A[i].second << "\n";
    }

    return 0;
}