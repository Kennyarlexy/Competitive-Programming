#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[100005];
string f(ll a, ll b) {
    string s = to_string(a), t = to_string(b);
    for (ll i = 0; i < s.length(); i++) {
        if (s[i] != t[i]) return t.substr(i);
    }

    return "";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    ll t = 0;
    while (true) {
        cin >> n;
        if (n == 0) break;
        for (ll i = 1; i <= n; i++) {
            cin >> A[i];
        }

        ll i = 1;
        cout << "Case " << ++t << ":\n";
        while (i <= n) {
            ll l = i;
            while (i+1 <= n && A[i+1] - A[i] == 1) i++;

            if (l == i) cout << "0" << A[l] << "\n";
            else cout << "0" << A[l] << "-" << f(A[l], A[i]) << "\n";

            i++;
        }
        cout << "\n";
    }
    
    return 0;
}