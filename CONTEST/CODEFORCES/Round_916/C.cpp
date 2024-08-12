#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

ll A[200005], B[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, k; cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        for (int i = 1; i <= n; i++) {
            cin >> B[i];
        }

        for (int i = 2; i <= n; i++) {
            A[i] += A[i-1];
            B[i] = max(B[i], B[i-1]);
        }

        ll _max = A[1] + B[1]*(k-1);
        for (int i = 2; i <= min(n, k); i++) {
            _max = max(_max, A[i] + B[i]*(k-i));
        }

        cout << _max << "\n";
    }
    
    return 0;
}

/*
1
10 10
10 10 10 10 10
10 10 10 10 10 
1 1 1 1 1          
1 1 1 1 1

1
5 1
5 4 3 2 1
999 999 999 999 999

1
2 10
1 2
5 10

1
5 10
10 10 10 10 10
10 10 100 10 10 

1
2 10
1 2
10 5



4
6 4
1 4 5 4 5 10
1 5 1 2 5 1
4 7
4 3 1 2
1 1 1 1
3 2
1 2 5
3 1 8
5 5
3 2 4 1 4
2 3 1 4 7


*/