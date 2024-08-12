#include <bits/stdc++.h>
#define ll long long
#define Point pair<ll, ll>
#define fi first
#define se second
using namespace std;

ll A[100005];
ll B[100005], C[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        set<ll> X, Y;
        for (int i = 0; i <= n; i++) {
            X.insert(i);
            Y.insert(i);
        }

        for (int i = 1; i <= n; i++) {
            if (X.count(A[i])) X.erase(A[i]);
            B[i] = *X.begin();
        }

        for (int i = n; i >= 1; i--) {
            if (Y.count(A[i])) Y.erase(A[i]);
            C[i] = *Y.begin();
        }

        ll j = -1;
        for (int i = 1; i < n; i++) {
            if (B[i] == C[i+1]) {
                j = i;
                break;
            }
        }

        if (j == -1) cout << "-1\n";
        else {
            cout << "2\n";
            cout << "1 " << j << "\n";
            cout << j+1 << " " << n << "\n";
        }
    }
    
    return 0;
}