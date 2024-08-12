#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second 

using namespace std;

int A[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n, k; cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        sort(A+1, A+1+n);
        for (int i = 2; i <= n; i++) {
            A[i] += A[i-1];
        }

        if (k >= A[n]) {
            ll y = (k - ((A[n]-A[n-1])*n - A[n])) / n;
            ll x = A[n] - A[n-1];
            ll ans = (x+y-1)*n + 1 + (k - A[n] - y*n);
            cout << ans << "\n";
        } else {
            int i;
            for (i = 2; i <= n; i++) {
                if ((A[i]-A[i-1])*i - A[i] > k) break;
            }

            ll x = A[i-1] - A[i-2];
            ll y = (k - (A[n] - A[n-1])) / (i-1);
            ll ans = (x+y-1)*n + 1 + (k - A[i-1] - y*(i-1));
            cout << ans << "\n";
        }
    }
    
    return 0;
}