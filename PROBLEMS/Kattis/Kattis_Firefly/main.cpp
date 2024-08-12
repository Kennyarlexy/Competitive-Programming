#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[500005], B[500005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, h; cin >> n >> h;
    for (int i = 1; i <= n; i+=2) {
        int a, b; cin >> a >> b;
        A[a]++; B[b]++;
    }

    for (int i = h-1; i >= 1; i--) {
        A[i] += A[i+1];
        B[i] += B[i+1];
    }

    int mn = INT_MAX, cnt = 0;
    for (int i = 1; i <= h; i++) {
        // mn = min(mn, A[i] + B[h-i+1]);
        int x = A[i] + B[h-i+1];
        if (x < mn) {
            mn = x;
            cnt = 1;
        } else if (x == mn) cnt++;
    }

    cout << mn << " " << cnt << "\n";
    
    return 0;
}