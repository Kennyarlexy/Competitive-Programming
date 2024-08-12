#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

char A[15][15];
int f(int i, int n) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
        if (A[i][j] == '1') cnt++;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        int a = -1, b = 0, cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> A[i][j];
                if (a == -1 && A[i][j] == '1') a = i;
                if (A[i][j] == '1') b = i, cnt++;
            }
        }

        if (f(a, n) == f(b, n)) cout << "SQUARE\n";
        else cout << "TRIANGLE\n";

    }
    
    return 0;
}