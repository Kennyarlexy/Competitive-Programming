#include <bits/stdc++.h>
#define ll long long
using namespace std;

string A[5];
bool defined[300];
bool used[100];
ll val[300];
ll cnt = 0;

ll cntNotUsed() {
    ll count = 0;
    for (ll i = 0; i <= 9; i++) {
        if (!used[i]) count++;
    }
    return count;
}

void f(ll i, ll prev, ll min_i) {
    if (i > min_i) {
        if (prev < 10 && A[1].length() == A[3].length()) {
            ll OK = true;
            for (ll j = i; j < A[1].length(); j++) {
                if (A[1][j] != A[3][j] || (!defined[A[1][j]] && (cntNotUsed() >= 2 || !used[0]))) {
                    OK = false;
                    break;
                }
            }
            if (OK) cnt++;
        } else if (prev >= 10) {
            if (A[1].length() == A[2].length() && A[3].length() == A[1].length()+1 && !defined[A[3][i]] && !used[1]) {
                cnt++;
            }
        }
        return;
    }
    if (cnt >= 2) return;

    if (!defined[A[1][i]] && !defined[A[2][i]] && !defined[A[3][i]]) {
        for (ll x = 0; x <= 9; x++)
        for (ll y = 0; y <= 9; y++) {
            ll z = (x+y)%10;
            if (used[x] || used[y] || used[z]) continue;
            if (((x == y) != (A[1][i] == A[2][i])) || ((x == z) != (A[1][i] == A[3][i])) || ((y == z) != (A[2][i] == A[3][i]))) 
                continue;
            
            defined[A[1][i]] = defined[A[2][i]] = defined[A[3][i]] = true;
            used[x] = used[y] = used[z] = true;
            val[A[1][i]] = x, val[A[2][i]] = y, val[A[3][i]] = z;

            f(i+1, x+y, min_i);

            defined[A[1][i]] = defined[A[2][i]] = defined[A[3][i]] = false;
            used[x] = used[y] = used[z] = false;
        }
    } else if (!defined[A[1][i] && !defined[A[2][i]]]) {
        for (ll x = 0; x <= 9; x++) {
            ll y = (prev >= 10 ? val[A[3][i]]-x-1 : val[A[3][i]]-x);
            if (used[x] || used[y]) continue;
            if (y < 0 || (x == y) != (A[1][i] == A[2][i])) continue;

            defined[A[1][i]] = defined[A[2][i]] = true;
            used[x] = used[y] = true;
            val[A[1][i]] = x, val[A[2][i]] = y;

            f(i+1, val[A[3][i]], min_i);

            defined[A[1][i]] = defined[A[2][i]] = false;
            used[x] = used[y] = false;
        }
    } else if (!defined[A[1][i]] && !defined[A[3][i]]) {
        for (ll x = 0; x <= 9; x++) {
            ll z = (x+val[A[2][i]]) % 10;
            if (used[x] || used[z]) continue;
            if ((x == z) != (A[1][i] == A[3][i])) continue;

            defined[A[1][i]] = defined[A[3][i]] = true;
            used[x] = used[z] = true;
            val[A[1][i]] = x, val[A[3][i]] = z;

            f(i+1, x+val[A[2][i]], min_i);
            defined[A[1][i]] = defined[A[3][i]] = false;
            used[x] = used[z] = false;
        }
    } else if (!defined[A[2][i]] && !defined[A[3][i]]) {
        for (ll y = 0; y <= 9; y++) {
            ll z = (y+val[A[2][i]]) % 10;
            if (used[y] || used[z]) continue;
            if ((y == z) != (A[2][i] == A[3][i])) continue;

            defined[A[2][i]] = defined[A[3][i]] = true;
            used[y] = used[z] = true;
            val[A[2][i]] = y, val[A[3][i]] = z;

            f(i+1, val[A[1][i]]+y, min_i);

            defined[A[2][i]] = defined[A[3][i]] = false;
            used[y] = used[z] = false;
        }
    } else if (!defined[A[1][i]]) {
        ll x = (prev >= 10 ? val[A[3][i]]-val[A[2][i]]-1 : val[A[3][i]]-val[A[2][i]]);
        if (x < 0 || used[x]) return;

        defined[A[1][i]] = true;
        used[x] = true;
        val[A[1][i]] = x;

        f(i+1, x+val[A[2][i]], min_i);

        defined[A[1][i]] = false;
        used[x] = false;
    } else if (!defined[A[2][i]]) {
        ll y = (prev >= 10 ? val[A[3][i]]-val[A[1][i]]-1 : val[A[3][i]]-val[A[1][i]]);
        if (y < 0 || used[y]) return;

        defined[A[2][i]] = true;
        used[y] = true;
        val[A[2][i]] = y;

        f(i+1, val[A[1][i]]+y, min_i);

        defined[A[2][i]] = false;
        used[y] = false;
    } else if (!defined[A[3][i]]) {
        ll z = (val[A[1][i]]+val[A[2][i]]) % 10;
        if (used[z]) return;

        defined[A[3][i]] = true;
        used[z] = true;
        val[A[3][i]] = z;

        f(i+1, val[A[1][i]]+val[A[2][i]], min_i);

        defined[A[3][i]] = false;
        used[z] = false;
    } else {
        if ((val[A[1][i]]+val[A[2][i]]) % 10 != val[A[3][i]]) return;
        f(i+1, val[A[1][i]]+val[A[2][i]], min_i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string line;
    while (true) {
        getline(cin, line);
        if (line == "#") break;
        memset(A, 0, sizeof(A));
        memset(defined, 0, sizeof(defined));
        memset(used, 0, sizeof(used));
        memset(val, 0, sizeof(val));
        cnt = 0;

        stringstream SS(line);
        ll i = 1;
        char ch;
        while (SS >> ch) {
            if (ch == '+' || ch == '=') i++;
            else A[i].push_back(ch);
        }

        if (A[1].length() < A[2].length()) swap(A[1], A[2]);
        for (ll i = 1; i <= 3; i++) {
            reverse(A[i].begin(), A[i].end());
        }

        f(0, 0, A[2].length()-1);
        cout << cnt << "\n";
    }
    
    return 0;
}