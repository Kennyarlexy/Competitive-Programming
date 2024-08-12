#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second 
using namespace std;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

vector<vector<ll>> A;

void f(int i, int j, int n, int m) {
    bool g = true;
    ll mx = LLONG_MIN;
    for (int k = 0; k < 4; k++) {
        int nr = i + dr[k];
        int nc = j + dc[k];

        if (nr < 1 || nr > n) continue;
        if (nc < 1 || nc > m) continue;
        
        if (A[i][j] <= A[nr][nc]) {
            g = false;
            break;
        }

        mx = max(mx, A[nr][nc]);
    }

    if (g) {
        A[i][j] = mx;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n, m; cin >> n >> m;
        A = vector<vector<ll>> (n+3, vector<ll> (m+3));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> A[i][j];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f(i, j, n, m);
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << A[i][j] << " \n"[j==m];
            }
        }
    }
    
    return 0;
}