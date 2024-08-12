#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        map<ll, ll> MP;
        int n; cin >> n;
        ll ans = 0;
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            MP[x]++;
            sum += x;
            if (sum % 2 == 0 && MP[sum/2] > 0) ans++; 
        }

        cout << ans << "\n";
    }
    
    return 0;
}