#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
#define Point pair<ll, ll>
using namespace std;

char A[] = {'m', 'a', 'p'};
char B[] = {'p', 'i', 'e'};

void rem(char ch, ll l, ll r, string &s) {
    for (int i = l; i <= r; i++) {
        if (s[i] == ch) s[i] = '.';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        string s; cin >> s;

        ll l = 0, r = 0;
        ll k = 0;
        map<char, ll> MP;

        ll x = 0;
        for (int i = 0; i < n; i++) {
            MP[s[i]]++;
            if (s[i] == A[k]) {
                r++;
            } else if (k+1 < 2 && s[i] == A[k+1]) {
                r++;
                k++;
            } else {
                if (k == 2) {
                    ll mn = LLONG_MAX;
                    for (auto [key, val] : MP) {
                        if (key != 'm' || key != 'a' || key != 'p') continue;

                        mn = min(mn, val);
                    }

                    x += mn;

                    if (MP['p'] == mn) {
                        rem('p', l, r, s);
                    } else {
                        rem('a', l, r, s);
                    }
                }
                l = i;
                r = i;
                k = 0;
                MP = {};
            }
        }

        string u;
        for (int i = 0; i < n; i++) {
            if (s[i] != '.') u.push_back(s[i]);
        }

        ll m = u.length();
        ll y = 0;
        MP = {};
        l = 0, r = 0, k = 0;
        for (int i = 0; i < m; i++) {
            MP[u[i]]++;
            if (u[i] == B[k]) {
                r++;
            } else if (k+1 < 2 && u[i] == B[k+1]) {
                r++;
                k++;
            } else {
                if (k == 2) {
                    ll mn = LLONG_MAX;
                    for (auto [key, val] : MP) {
                        if (key != 'p' || key != 'i' || key != 'e') continue;

                        mn = min(mn, val);
                    }

                    y += mn;
                }
                l = i;
                r = i;
                k = 0;
                MP = {};
            }
        }
        
        ll ans = x + y;
        cout << ans << "\n";
    }

    
    return 0;
}