#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

int A[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        int x = 1, y = n - n%2;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                A[i] = x;
                x += 2;
            } else {
                A[i] = y;
                y -= 2;
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << A[i] << " \n"[i==n];
        }
    }
    
    return 0;
}