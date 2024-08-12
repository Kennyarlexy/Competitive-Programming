#include <bits/stdc++.h>
#define ll long long
using namespace std;

string A[3][10] = {
    {".*", "*.", "*.", "**", "**", "*.", "**", "**", "*.", ".*"},
    {"**", "..", "*.", "..", ".*", ".*", "*.", "**", "**", "*."},
    {"..", "..", "..", "..", "..", "..", "..", "..", "..", ".."}
};

map<string, ll> MP = {
    {"*.....", 1},
    {"*.*...", 2},
    {"**....", 3},
    {"**.*..", 4},
    {"*..*..", 5},
    {"***...", 6},
    {"****..", 7},
    {"*.**..", 8},
    {".**...", 9},
    {".***..", 0}
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        char type; cin >> type;
        if (type == 'S') {
            string t; cin >> t;
            for (ll i = 0; i < 3; i++) {
                for (ll j = 0; j < n; j++) {
                    cout << A[i][t[j]-'0'] << " \n"[j==n-1];
                }
            }
        } else {
            string B[n];
            for (ll i = 0; i < 3; i++) {
                for (ll j = 0; j < n; j++) {
                    string t; cin >> t;
                    B[j] += t;
                }
            }

            for (ll j = 0; j < n; j++) {
                cout << MP[B[j]];
            }
            cout << "\n";
        }
    }
    
    return 0;
}

/*
10
S
1234567890
3
B
*. *. **
.. *. ..
.. .. ..
2
S
00
0

10
B
*. *. ** ** *. ** ** *. .* .*
.. *. .. .* .* *. ** ** *. **
.. .. .. .. .. .. .. .. .. ..
*/