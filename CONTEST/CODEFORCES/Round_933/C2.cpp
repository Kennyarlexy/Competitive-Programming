#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
#define Point pair<ll, ll>
using namespace std;

ll f(string &s, string &t) {
    int n = s.length();
    int m = t.length();
    int j = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (j == m) {
            cnt++;
            j = 0;
        }

        if (s[i] == t[j]) j++;
        else if (s[i] == t[0]) j = 1;
        else j = 0;
    }
    if (j == m) cnt++;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        string s; cin >> s;
        string x = "map", y = "pie", z = "mapie";
        ll a = f(s, x), b = f(s, y), c = f(s, z);
        ll ans = a + b - c;
        cout << ans << "\n";
    }
    
    return 0;
}