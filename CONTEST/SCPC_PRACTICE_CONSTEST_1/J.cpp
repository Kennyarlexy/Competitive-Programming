#include <bits/stdc++.h>
#define ll long long
using namespace std;

char A[105][105];
queue<pair<int, int>> X, O;

void generate(int n, int m) {
    char a = 'X', b = 'O';
    for (int i = 1; i <= n; i+=2) {
        for (int j = 1; j <= m; j++) {
            A[i][j] = (j % 2 == 1) ? a : b;
            A[i+1][j] = (j % 2 == 1) ? b : a;
        }
        swap(a, b);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // cout << A[i][j];
            if (A[i][j] == 'X') X.emplace(i, j);
            else O.emplace(i, j);
        }
        // cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;

    if (n % 2 == 1) generate(m, n);
    else generate(n, m);

    for (int i = 1; i <= n*m; i++) {
        char ch; cin >> ch;
        if (ch == 'X') {
            auto [r, c] = X.front(); X.pop();
            if (n % 2 == 1) swap(r, c);
            cout << r << " " << c << endl;
        } else {
            auto [r, c] = O.front(); O.pop();
            if (n % 2 == 1) swap(r, c);
            cout << r << " " << c << endl;
        }
    }
    
    return 0;
}