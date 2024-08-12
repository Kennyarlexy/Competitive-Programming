#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[100005];
ll L[100005];
ll R[100005];
ll cnt = 0;
void merge_sort(ll l, ll r) {
    if (l == r) return;

    ll m = (l+r)/2;
    merge_sort(l, m);
    merge_sort(m+1, r);

    
    for (ll il = l; il <= m; il++) {
        L[il] = A[il];
    }

    for (ll ir = m+1; ir <= r; ir++) {
        R[ir] = A[ir];
    }

    ll i = l, il = l, ir = m+1;
    while (il <= m && ir <= r) {
        if (L[il] <= R[ir]) {
            A[i] = L[il++];
        } else {
            A[i] = R[ir++];
            cnt += (m-il+1);
        }
        i++;
    }

    while (il <= m) {
        A[i++] = L[il++];
    }

    while (ir <= r) {
        A[i++] = R[ir++];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N;
    while (true) {
        cin >> N;
        if (N == 0) break;

        for (ll i = 0; i < N; i++) {
            cin >> A[i];
        }

        cnt = 0;
        merge_sort(0, N-1);
        if (cnt % 2 == 1) cout << "Marcelo\n";
        else cout << "Carlos\n";
    }
    
    return 0;
}