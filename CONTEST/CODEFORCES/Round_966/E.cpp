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
        ll n, m, k; cin >> n >> m >> k;
        int w; cin >> w;
        for (int i = 1; i <= w; i++) {
            cin >> A[i];
        }

        sort(A+1, A+1+w, greater<ll> ());
        
        vector<ll> B; B.reserve(n*m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ll left = max(1LL, j - (k-1));
                ll right = min(m, j + (k-1));

                ll top = max(1LL, i - (k-1));
                ll bot = min(n, i + (k-1));

                ll H = right-left+1;
                ll V = bot-top+1;

                ll X = (H-k+1)*(V-k+1);
                B.push_back(X);
            }
        }

        sort(B.begin(), B.end(), greater<ll> ());
        ll ans = 0;
        for (int i = 1, j = 0; i <= w; i++, j++) {
            ans += A[i]*B[j];
        }

        cout << ans << "\n";
    }
    
    return 0;
}