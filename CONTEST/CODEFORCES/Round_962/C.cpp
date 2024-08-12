#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

int X[200005][30], Y[200005][30];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, q; cin >> n >> q;
        string s1, s2; cin >> s1 >> s2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                X[i][j] = 0;
                Y[i][j] = 0;
            }
            X[i][s1[i]-'a'] = 1;
            Y[i][s2[i]-'a'] = 1;
            if (i > 0) for (int j = 0; j < 26; j++) {
                X[i][j] += X[i-1][j];
                Y[i][j] += Y[i-1][j];
            }
        }

        for (int qq = 1; qq <= q; qq++) {
            int l, r; cin >> l >> r;
            l--, r--;

            int ans = 0;
            for (int i = 0; i < 26; i++) {
                int A = X[r][i];
                int B = Y[r][i];
                if (l > 0) {
                    A -= X[l-1][i];
                    B -= Y[l-1][i];
                }
                ans += abs(A-B);
            }
            cout << ans / 2 << "\n";
        }
    }
    
    return 0;
}

/*
1
6 3
uwuwuw
wuwuwu
2 4
1 3
1 6
*/