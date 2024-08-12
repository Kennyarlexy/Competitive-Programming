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
        ll n, k; cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        sort(A+1, A+1+n);
        
        int i;
        for (i = 2; i <= n; i++) {
            ll x = (A[i] - A[i-1])*(i-1);
            if (k < x) {
                break;
            }
            k -= x;
        }

        i--;
        ll y = k/i;
        ll x = y*i;
        k -= x;
        ll ans = (A[i] + y)*n - i + 1 + k;
    
        cout << ans << "\n";
    }
    
    return 0;
}