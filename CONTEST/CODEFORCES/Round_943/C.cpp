#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

ll A[505];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i < n; i++) {
            cin >> A[i];
        }

        ll x = 9e8;
        for (int i = 1; i <= n; i++) {
            cout << x << " \n"[i==n];
            x += A[i];
        }
    }
    
    return 0;
}