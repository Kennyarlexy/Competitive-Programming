#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[100005];
ll cnt = 0;

void merge_sort(ll l, ll r) {
    if (l >= r) return;
    ll m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m+1, r);

    ll len = r - l + 1;
    ll res[len];
    ll i = 0;
    ll iL = l;
    ll iR = m+1;

    while (iL <= m && iR <= r) {
        if (A[iL] <= A[iR]) {
            res[i++] = A[iL++];
        } else {
            cnt += (m-iL+1);
            res[i++] = A[iR++];
        }
    }

    while (iL <= m) {
        res[i++] = A[iL++];
    }

    while (iR <= r) {
        res[i++] = A[iR++];
    }

    ll j = l;
    for (auto& data : res) {
        A[j++] = data;
    }
}

int main() {
    fast_io();
    //use ll when possible!
    ll N; cin >> N;
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    merge_sort(0, N-1);
    cout << cnt << "\n";

    return 0;
}