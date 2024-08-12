#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[105], B[105];
int cnt[105];
int C[2][3] = {
    {1, 2, 1},
    {1, 3, 1},
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        memset(cnt, 0, sizeof(cnt));
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        int pairCnt = 0;


        for (int i = 1; i <= n; i++) {
            if (pairCnt < 2) {
                cnt[A[i]]++;
                int j = min(cnt[A[i]], 3) - 1;
                B[i] = C[pairCnt][j];

                if (cnt[A[i]] == 2) pairCnt++;
            } else {
                B[i] = 1;
            }
        }
        if (pairCnt < 2) {
            cout << "-1\n";
        } else {
            for (int i = 1; i <= n; i++) {
                cout << B[i] << " \n"[i==n];
            }
        }
    }
    
    return 0;
}