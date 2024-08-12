#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second 
using namespace std;

ll A[300005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, k; cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        
        map<int, ll> MP;
        for (int i = 1; i <= n; i++) {
            int a; cin >> a;
            MP[abs(a)] += A[i];
        }

        ll bullet = 0;
        ll y = 0;
        bool f = true;
        for (auto& [x, hp] : MP) {
            ll d = x - y;
            bullet += k*d;
            bullet -= hp;
            if (bullet < 0) {
                f = false;
                break;
            }
            y = x;
        }

        cout << (f ? "YES":"NO") << "\n";
    }
    
    return 0;
}