#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int LEFT = 0, RIGHT = 1;

int A[200005], C[200005];
int B[32][2][2]; //[index][bit][min/max];

int f(int S, int i, int j, int k, int z) {
    if (j < i) return -1;
    
    if (k == -1) {
        return S ^ z;
    }

    int bit = (S & (1 << k)) > 0;
    cout << "found bit " << bit << " at index " << k << " - ";
    cout << "i = " << i << "\n";
    int a = max(i, B[k][1-bit][LEFT]);
    int b = min(j, B[k][1-bit][RIGHT]);
    cout << "a = " << a << " b = " << b << "\n";

    if (a <= b) {
        cout << "bit " << 1-bit << " possible\n";
        return f(S, a, b, k-1, z | ((1-bit) << k));
    }
    
    int c = max(i, B[k][bit][LEFT]);
    int d = min(j, B[k][bit][RIGHT]);

    if (c <= d) {
        cout << "same bit possible\n";
        return f(S, c, d, k-1, z | (bit << k));
    }

    cout << "no intersection\n";
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        C[i] = A[i];
        C[i] ^= C[i-1];
    }

    int w = __bit_width(n);
    for (int i = w-1; i >= 0; i--) {
        for (int j = 1; j <= n; j++) {
            int bit = (A[j] & (1 << i)) > 0;
            if (B[i][bit][LEFT] == 0) B[i][bit][LEFT] = j;
            
            B[i][bit][RIGHT] = j;
        }
    }

    int Q; cin >> Q;
    for (int q = 1; q <= Q; q++) {
        int L, R; cin >> L >> R;
        int S = C[R] ^ C[L-1];
        int ans = max(f(S, 1, L-1, w-1, 0), f(S, R+1, n, w-1, 0));

        ans = max(ans, S);
        cout << ans << "\n";
    }

    cout << B[3][1][LEFT] << " " << B[3][1][RIGHT] << "\n";
    
    return 0;
}

/*
5
1 2 3 4 5
1
1 3
*/