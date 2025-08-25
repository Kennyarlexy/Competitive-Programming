#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

int A[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, k; cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        map<int, int> MP, MP2;
        int cnt = 0;
        bool extra = false;
        for (int i = 1; i <= n; i++) {
            if (MP[k-A[i]] == 0) {
                MP[A[i]]++;
            } else {
                cnt++;
                MP[k-A[i]]--;

                int mn = min(k-A[i], A[i]);
                MP2[mn]++;
                if (MP2[mn] > 1) extra = true;
            }
        }

        int rem = n - 2*cnt;
        if (rem % 2 == 1) {
            if (extra) cout << cnt - 1 << "\n";
            else cout << "0\n";
        } else cout << cnt << "\n";
    }
    
    return 0;
}

/*
1
11 7
1 2 3 4 5 6 3 4 10 10 10

*/