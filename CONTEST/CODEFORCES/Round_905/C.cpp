#include <bits/stdc++.h>
#define ll long long
using namespace std;


int A[200005];
int cnt_mod[10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, k; cin >> n >> k;
        memset(cnt_mod, 0, sizeof(cnt_mod));
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        int max_mod = 0;
        for (int i = 1; i <= n; i++) {
            cnt_mod[A[i] % k]++;
            max_mod = max(max_mod, A[i] % k);
        }

        if (cnt_mod[0] >= 1) cout << "0\n";
        else if (k == 2 || k == 3 || k == 5) {
            cout << k - max_mod << "\n";
        } else {
            if (cnt_mod[2] >= 2) cout << "0\n";
            else if (cnt_mod[2] == 1 && cnt_mod[1] + cnt_mod[3] >= 1) cout << "1\n";
            else if (cnt_mod[1] + cnt_mod[3] >= 2) cout << min(2, k - max_mod) << "\n";
            else cout << k-max_mod << "\n";
        }
    }
    
    return 0;
}

