#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

vector<int> Z;
string s;

void z_algo(int n) {
    Z = vector<int> (n+5);
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        Z[i] = (y < i) ? 0 : min(y-i+1, Z[i-x]);
        while (i+Z[i] < n && s[Z[i]] == s[i+Z[i]]) {
            Z[i]++;
        }
        if (i+Z[i]-1 > y) {
            x = i; y = i+Z[i]-1;
        }
    }
}

vector<int> cnt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, l, r; cin >> n >> l >> r;
        cin >> s;
        z_algo(n);
        cnt = vector<int> (n+5);
        for (int i = 0; i < n; i++) {
            cnt[Z[i]]++;
        }

        int mx = 0;
        for (int i = 0; i <= n; i++) {
            if (cnt[i] >= 2) mx = max(mx, cnt[i]);
        }

        cout << mx << "\n";
    }
    
    return 0;
}