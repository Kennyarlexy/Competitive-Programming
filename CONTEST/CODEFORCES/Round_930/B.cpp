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
        ll n; cin >> n;
        string a, b; cin >> a >> b;
        
        ll k = 0;
        ll j = n-1;
        for (int i = 0; i < n-1; i++) {
            if (a[i+1] == b[i]) k++;
            else if (a[i+1] == '0') k = 0;
            else {
                j = i;
                break;
            }
        }
        // cout << "j = " << j << "\n";
        string ans = a.substr(0, j+1) + b.substr(j);
        cout << ans << "\n";
        cout << k+1 << "\n";
    }
    
    return 0;
}