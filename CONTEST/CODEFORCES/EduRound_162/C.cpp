#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second 
using namespace std;

ll A[300005], B[300005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, Q; cin >> n >> Q;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            A[i]--;
            
            B[i] = B[i-1] + (A[i] == 0);
            A[i] += A[i-1];
        }

        for (int q = 1; q <= Q; q++) {
            int l, r; cin >> l >> r;
            if (l == r) cout << "NO\n";
            else {
                if (B[r] - B[l-1] > A[r] - A[l-1]) cout << "NO\n";
                else cout << "YES\n";

            }
        }
    }
    
    return 0;
}

/*
3
5 1
3 3 1 1 1
1 5

6 1
3 3 1 1 1 1
1 6

7 1
3 3 1 1 1 1 1
1 7


2
3 1
1 1 1
1 3
3 1
1 1 1
1 3

3
5 1
3 3 1 1 1
1 5
5 1
3 1 1 1 3
1 5
5 1
1 1 1 3 3
1 5

2
4 1
4 1 1 1
1 4
4 1
1 4 1 1
1 4

1
4 1
3 1 1 1
1 4

1
2 1
1 2
1 2
*/