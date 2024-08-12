#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[10005], B[10005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int X, Y;
        cin >> X >> Y;
        
        for (int i = 1; i <= X; i++) cin >> A[i];
        for (int i = 1; i <= Y; i++) cin >> B[i];

        sort(A + 1, A + X + 1);
        sort(B + 1, B + Y + 1);
        
        if (X == 0 && Y == 0) {
            cout << "0 0\n";
            continue;
        }
        
        if (X == 0) {
            cout << "0 0\n";
            continue;
        }

        if (Y == 0) {
            cout << A[X] << " 0\n";
            continue;
        }

        ll a = 0, b = X;
        for (int i = 1; i <= X; i++) {
            int k = lower_bound(B+1, B+Y+1, A[i]) - B - 1;
            ll c = X - i + k;
            if (c < b) {
                b = c;
                a = A[i];
            }
        }

        cout << a << " " << b << "\n";
    }
    
    return 0;
}