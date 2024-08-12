#include <bits/stdc++.h>
#define ll long long
using namespace std;

string A[5];
set<char> S;
vector<char> V;
char val[300];
bool used[300];

ll cnt = 0;

void f(ll i, ll n) {
    if (cnt >= 2) return;
    if (i == n) {
        string x = A[1], y = A[2], z = A[3];
        for (auto& d : x) d = val[d];
        for (auto& d : y) d = val[d];
        for (auto& d : z) d = val[d];

        if (x[0] == '0' || y[0] == '0' || z[0] == '0')
            return;
        
        ll a = stoll(x), b = stoll(y), c = stoll(z);
        if (a + b == c) {
            cnt++;
        }
        return;
    }
    
    for (char d = '0'; d <= '9'; d++) {
        if (used[d]) continue;
        val[V[i]] = d;
        used[d] = true;
        f(i+1, n);
        used[d] = false;
    }
}

map<char, ll> MP {
    {'I', 1},
    {'X', 10},
    {'C', 100},
    {'M', 1000},
    {'V', 5},
    {'L', 50},
    {'D', 500}
};

ll rtoll(string s) {
    ll n = 0;
    ll i = 0;
    while (i < s.length()) {
        if (i < s.length()-1 && MP[s[i+1]] > MP[s[i]]) {
            n += (MP[s[i+1]] - MP[s[i]]);
            i++;
        } else {
            n += MP[s[i]];
        }
        i++;
    }
    return n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string line;
    while (true) {
        getline(cin, line);
        if (line == "#") break;
        memset(A, 0, sizeof(A));
        memset(val, 0, sizeof(val));
        memset(used, 0, sizeof(used));
        S = {}, V = {};
        cnt = 0;

        stringstream SS(line);
        ll i = 1;
        char ch;
        while (SS >> ch) {
            if (ch == '+' || ch == '=') i++;
            else {
                A[i].push_back(ch);
                S.insert(ch);
            }
        }

        for (auto& d : S) {
            V.push_back(d);
        }

        if (rtoll(A[1]) + rtoll(A[2]) == rtoll(A[3]))
            cout << "Correct ";
        else 
            cout << "Incorrect ";
        
        f(0, V.size());
        
        if (cnt >= 2) cout << "ambiguous\n";
        else if (cnt == 1) cout << "valid\n";
        else cout << "impossible\n";
    }

    return 0;
}