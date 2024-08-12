#include <bits/stdc++.h>
#define ll long long
using namespace std;

char A[205][205];
string bit_D;

char eval(int a, int b, int c, int d) {
    for (int i = a; i <= c; i++) {
        for (int j = b; j <= d; j++) {
            if (A[i][j] != A[a][b]) return 'D';
        }
    }

    return A[a][b];
}

void f(int a, int b, int c, int d) {
    if (c < a || d < b) return;
    
    char val = eval(a, b, c, d);
    bit_D.push_back(val);
    if (val == 'D') {
        int x = (a+c) / 2;
        int y = (b+d) / 2;
// cout << "x = " << x << "    y = " << y << "\n";
// return;
        f(a, b, x, y);
        f(a, y+1, x, d);
        f(x+1, b, c, y);
        f(x+1, y+1, c, d);
    }
}


void put(int a, int b, int c, int d, char val) {
    for (int i = a; i <= c; i++) {
        for (int j = b; j <= d; j++) {
            A[i][j] = val;
        }
    }
}

int i = 0;
void g(int a, int b, int c, int d) {
    if (c < a || d < b) return;

    if (bit_D[i] != 'D') {
        put(a, b, c, d, bit_D[i]);
        i++;
        return;
    }

    int x = (a+c) / 2;
    int y = (b+d) / 2;
    i++;
    g(a, b, x, y);
    g(a, y+1, x, d);
    g(x+1, b, c, y);
    g(x+1, y+1, c, d);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        char type; cin >> type;
        if (type == '#') break;
        int n, m; cin >> n >> m;

        if (type == 'B') {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    cin >> A[i][j];
                }
            }

            bit_D = {};
            f(1, 1, n, m);
            cout << "D" << setw(4) << n << setw(4) << m << "\n";
            
            int x = 0;
            for (auto ch : bit_D) {
                if (x == 50) {
                    cout << "\n";
                    x = 0;
                }
                cout << ch;
                x++;
            }
            cout << "\n";
            
        } else {
            cin >> bit_D;
            i = 0;
            g(1, 1, n, m);
            cout << "B" << setw(4) << n << setw(4) << m << "\n";
            int x = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (x == 50) {
                        cout << "\n";
                        x = 0;
                    }
                    x++;
                    cout << A[i][j];
                }
            }
            cout << "\n";
        }
    }

// cout << "OK\n";
    
    return 0;
}