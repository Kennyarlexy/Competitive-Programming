#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[200005];
int B[32][200005]; // sparse table OR
int C[200005];

int get_left_most_zero(int X) {
    int k = 32 - __builtin_clz(X) - 1;
    X = ~X;
    for (int i = k-1; i >= 0; i--) {
        if ((1 << i) & X) return i;
    }
    return -1;
}

int MSOne(int X) {
    int k = 32 - __builtin_clz(X) - 1;
    return (1 << k);
}

int query(int i, int j) {
    int len = j-i+1;
    int k = 32 - __builtin_clz(len) - 1;
    int x = (1 << k);
    if (__builtin_popcount(len) == 1) x /= 2;

    return B[k][i] | B[k][i+x];
}

int f(int i, int j, int Z) {
    if (j < i) return 0;
    if (i == j) {
        return Z ^ C[i];
    }
    
    assert(i <= j);
    int m = (i + j) / 2;
    int A = query(i, m);
    int B = query(m+1, j);
    int X = MSOne(A);
    int Y = MSOne(B);
    
    if (X > Y) return f(i, m, Z);
    else if (X < Y) return f(m+1, j, Z);
    else {
        return max(f(i, m, Z), f(m+1, j, Z));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test = 2;
    
    for (int i = 1; i <= 10; i++) {
        cout << i << " -> " << get_left_most_zero(i) << "\n";
    }
    return 0;
    
    
    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        C[i] = A[i];
        A[i] ^= A[i-1];
        B[0][i] = A[i];
    }

    // build sparse table
    for (int i = 1; i*2 <= n; i*=2) {
        int k = 32 - __builtin_clz(i);
        for (int j = 1; j+i-1 <= n; j++) {
            B[k][j] = B[k-1][j] | B[k-1][j+i];
        }
    }
    
    int Q; cin >> Q;
    for (int q = 1; q <= Q; q++) {
        int L, R; cin >> L >> R;
        int Z = A[R] ^ A[L-1];
        
        int ans = max(f(1, L-1, Z), f(R+1, n, Z));
        ans = max(Z, ans);
        cout << ans << "\n";
    }
    
    return 0;
}


/*
7
1 2 3 4 5 6 7
10
1 2
2 2
1 3
1 5
1 7
5 7
3 5
3 3
4 4
5 5


10
1 2 3 4 5 6 7 8 9 10
10
1 2
2 2
1 3
1 5
1 7
5 7
3 5
3 3
4 4
5 5
*/