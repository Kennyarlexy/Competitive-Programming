#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[10005];
int I[10005];
int D[10005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        vector<int> V;
        for (int i = 1; i <= n; i++) {
            int k = lower_bound(V.begin(), V.end(), A[i]) - V.begin();
            if (k == V.size()) V.push_back(A[i]);
            else V[k] = A[i];

            I[i] = k+1;
        }

        V = {};
        for (int i = n; i >= 1; i--) {
            int k = lower_bound(V.begin(), V.end(), A[i]) - V.begin();
            if (k == V.size()) V.push_back(A[i]);
            else V[k] = A[i];

            D[i] = k+1;
        }

        int mx = INT_MIN;
        for (int i = 1; i <= n; i++) {
            mx = max(mx, min(I[i], D[i])*2 - 1);
        }

        cout << mx << "\n";
    }
    
    return 0;
}