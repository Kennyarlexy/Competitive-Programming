#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        vector<bool> V(n+5);
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            V[A[i]] = true;
        }

        vector<int> V2;
        for (int i = 1; i <= n; i++) {
            if (!V[i]) V2.push_back(i);
        }

        vector<bool> V3(n+5);
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (V3[A[i]]) {
                ans.push_back(V2.back()); V2.pop_back();
            } else {
                ans.push_back(A[i]);
            }
            V3[A[i]] = true;
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i==n-1];
        }
    }
    
    return 0;
}