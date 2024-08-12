#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

int A[30][200005], B[30][200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, Q; cin >> n >> Q;
        string s1, s2; cin >> s1 >> s2;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = (s1[j] == 'a' + i);
                if (j > 0) A[i][j] += A[i][j-1];

                B[i][j] = (s2[j] == 'a' + i);
                if (j > 0) B[i][j] += B[i][j-1];
            }
        }

        for (int q = 1; q <= Q; q++) {
            int l, r; cin >> l >> r;
            l--, r--;
            int k = 0;
            for (int i = 0; i < 26; i++) {
                int x = A[i][r];
                if (l > 0) x -= A[i][l-1];

                int y = B[i][r];
                if (r > 0) y -= B[i][l-1];

                k += min(x, y);
            }

            int ans = r-l+1 - k;
            cout << ans << "\n";
        }
    }
    
    return 0;
}