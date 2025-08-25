#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

int A[1005];
int B[1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    iota(B+1, B+1+n, 1);

    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++) {
        int j = 1;
        while (j < n && B[j] != A[i]) j++;

        for (int k = j + 1; k <= n; k++) {
            ans.push_back({B[k], B[k-1]});
            swap(B[k], B[k-1]);
        }

        for (int k = n; k > i; k--) {
            ans.push_back({B[k], B[k-1]});
            swap(B[k], B[k-1]);
        }
    }

    int m = ans.size();
    cout << m << "\n";
    for (int i = 0; i < m; i++) {
        cout << ans[i].fi << " " << ans[i].se << "\n";
    }
    
    return 0;
}

/*
2
3
1

*/