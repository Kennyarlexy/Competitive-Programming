#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll A[100005];
ll B[100005];
ll T[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> T[i];
    }

    for (int i = 1; i <= N;i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }

    ll ans = 0;
    for (int i = N; i >= 2; i--) {
        ll need = max(0LL, B[i] - A[i]);
        ans += need * T[i-1];
        A[i-1] -= need;
    }

    if (A[1] < B[1]) cout << "-1\n";
    else cout << ans << "\n";
    
    return 0;
}

/*
3
1 1
5 0 0
0 0 6
*/