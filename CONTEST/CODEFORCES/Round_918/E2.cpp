#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll A[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        unordered_set<ll> S; S.reserve(n+5); S.insert(0);
        ll sum = 0;
        bool OK = false;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) sum += A[i];
            else sum -= A[i];

            if (S.count(sum) == 1) {
                OK = true;
                break;
            }

            S.insert(sum);
        }

        if (OK) cout << "YES\n";
        else cout << "NO\n";
    }

    
    return 0;
}