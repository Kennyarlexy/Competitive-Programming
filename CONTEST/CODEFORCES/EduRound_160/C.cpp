#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

ll cnt[35];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int M; cin >> M;
    for (int m = 1; m <= M; m++) {
        ll t, v; cin >> t >> v;
        if (t == 1) {
            cnt[v]++;
        } else {
            ll utang = 0;
            for (int j = 32; j >= 0; j--) {
                utang *= 2;
                if (v & (1LL << j)) utang++;
                
                utang -= min(utang, cnt[j]);
            }

            if (utang == 0) cout << "YES\n";
            else cout << "NO\n";
        }
    }   
    
    return 0;
}