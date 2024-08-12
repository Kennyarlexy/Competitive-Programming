#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second 

using namespace std;
pair<int, int> f(string &s) {
    int z = 0;
    int len = s.length();
    for (int i = len-1; i >= 0; i--) {
        if (s[i] != '0') break;
        z++;
    }
    return {z, len};
}

pair<int, int> A[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m; cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            string s; cin >> s;
            A[i] = f(s);
        }

        sort(A+1, A+n+1, greater<pair<int, int>> ());

        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += A[i].se;
            if (i % 2 == 1) ans -= A[i].fi;
        }

        if (ans > m) cout << "Sasha\n";
        else cout << "Anna\n";
    }
    
    return 0;
}