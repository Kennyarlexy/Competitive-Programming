#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

pair<ll, string> A[] = {
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"}
};

string lltor(ll n) {
    string roman;
    for (ll i = 0; i < 13; i++) {
        while (n >= A[i].fi) {
            roman += A[i].se;
            n -= A[i].fi;
        }
    }
    return roman;
}

ll cnt[4005];
map<char, ll> MP = {
    {'I', 1},
    {'V', 2},
    {'X', 2},
    {'L', 2},
    {'C', 2},
    {'D', 3},
    {'M', 4}
};

ll f(string s) {
    ll n = 0;
    for (auto& d : s) n += MP[d];
    return n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (ll i = 1; i <= 3999; i++) {
        cnt[i] = f(lltor(i));
    }

    ll n;
    while (cin >> n) {
        cout << cnt[n] << "\n";
    }
    
    return 0;
}