#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

int A[200005];
int B[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        for (int i = 1; i <= n; i++) {
            cin >> B[i];
        }
        
        int a = 0, b = 0, x = 0, y = 0;
        for (int i = 1; i <= n; i++) {
            if (A[i] == B[i]) {
                if (A[i] == 1) x++;
                else if (A[i] == -1) y++;
            } else {
                if (A[i] == 1) a++;
                else if (B[i] == 1) b++;
            }
        }

        if (a > b) swap(a, b);
        int d = min(b - a, x);
        a += d;
        x -= d;
        y -= x;

        // cout << x << " " << y << "\n";

        if (a == b) {
            int ans = (y < 0) ? a - y/2 : a - (y+1)/2;
            cout << ans << "\n";
        } else {
            int d2 = min(y, b - a);
            b -= d2;
            y -= d2;
            if (a == b) {
                int ans = a - (y+1)/2;
                cout << ans << "\n";
            } else {
                cout << a << "\n";
            }
        }
    }
    
    return 0;
}

/*
1
2
-1 1
1 -1

1
3
1 1 1
1 1 1

1
5
1 1 1 1 -1
1 1 1 1 -1
*/