#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second 

using namespace std;

ll A[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            sum += A[i];
        }

        ll k = sum / n;

        bool ans = true;
        for (int i = 1; i < n; i++) {
            if (A[i] < k) {
                ans = false;
                break;
            }
            A[i+1] += (A[i] - k);
            A[i] = k;
        }

        cout << (ans ? "YES":"NO") << "\n";
    }
    
    return 0;
}