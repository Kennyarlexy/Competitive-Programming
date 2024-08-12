#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[32][1005];
void print(int n) {
    for (int i = 1; i <= n; i++) {
        cout << A[0][i] << " \n"[i==n];
    }
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);  
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[0][i];
    }

    int w = 1;
    for (int i = 1; 2*w <= n; i++) {
        for (int j = 1; j + 2*w - 1 <= n; j++) {
            A[i][j] = min(A[i-1][j], A[i-1][j+w]);
        }
        w *= 2;
    }

    int Q; cin >> Q;
    for (int q = 1; q <= Q; q++) {
        // print(n);
        int i, j; cin >> i >> j;
        int w = j-i+1;

        int k = 31 - __builtin_clz(w);
        int ans = min(A[k][i], A[k][j - (1 << k) + 1]);
        cout << ans << "\n";
    }
    
    return 0;
}

/*
8
1 3 4 8 6 1 4 2
10
1 1
2 2
3 3
4 4
5 5
1 3
1 5
3 6
3 8
1 8
*/