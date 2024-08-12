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
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        for (int i = 1+(n%2); i < n; i+=2) {
            if (A[i] > A[i+1]) swap(A[i], A[i+1]);
        }

        bool ans = true;
        for (int i = 2; i <= n; i++) {
            if (A[i] < A[i-1]) {
                ans = false;
                break;
            }
        }

        cout << (ans ? "YES":"NO") << "\n";
    }
    
    return 0;
}