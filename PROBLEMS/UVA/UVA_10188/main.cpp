#include <bits/stdc++.h>
#define ll long long
using namespace std;

string A[105], B[105];
bool match(string& s, string& t) {
    if (s.length() != t.length()) return false;

    for (ll i = 0; i < s.length(); i++) {
        if (s[i] != t[i]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    ll t = 0;
    while (true) {
        cin >> n;
        if (n == 0) break;

        cin.ignore(1000, '\n');
        for (ll i = 1; i <= n; i++) {
            getline(cin, A[i]);
        }

        ll m; cin >> m;
        cin.ignore(1000, '\n');
        for (ll i = 1; i <= m; i++) {
            getline(cin, B[i]);
        }

        bool AC = true;
        if (n != m) AC = false;
        else {
            for (ll i = 1; i <= n; i++) {
                if (!match(A[i], B[i])) {
                    AC = false;
                    break;
                }
            }
        }

        cout << "Run #" << ++t << ": ";
        
        if (AC) {
            cout << "Accepted\n";
        } else {
            string a;
            for (ll i = 1; i <= n; i++) {
                for (auto& ch : A[i]) {
                    if (isdigit(ch)) a += ch;
                }
            }

            string b;
            for (ll i = 1; i <= m; i++) {
                for (auto& ch : B[i]) {
                    if (isdigit(ch)) b += ch;
                }
            }

            bool PE = match(a, b);
            if (PE) {
                cout << "Presentation Error\n";
            } else {
                cout << "Wrong Answer\n";
            }
        }
    }
    
    return 0;
}

/*
2
The answer is: 10
The answer is: 5
2
The answer is: 10
The answer is: 5
2
The answer is: 10
The answer is: 5
2
The answer is: 10
The answer is: 15
2
The answer is: 10
The answer is:  5
2
The answer is: 10
The answer is: 5
3
Input Set #1: YES
Input Set #2: NO
Input Set #3: NO
3
Input Set #0: YES
Input Set #1: NO
Input Set #2: NO
1
1 0 1 0
1
1010
1
The judges are mean!
1
The judges are good!
0

2
..1
...
1
1
0
*/