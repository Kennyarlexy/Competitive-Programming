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

map<char, ll> MP = {
    {'M', 1000},
    {'D', 500},
    {'C', 100},
    {'L', 50},
    {'X', 10},
    {'V', 5},
    {'I', 1}
};

ll rtoll(string s) {
    ll num = 0;
    ll i = 0;
    while (i < s.length()) {
        if (i < s.length()-1 && MP[s[i+1]] > MP[s[i]]) {
            num += (MP[s[i+1]] - MP[s[i]]);
            i++;
        } else {
            num += MP[s[i]];
        }
        i++;
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while (cin >> s) {
        if (s[0] >= '1' && s[0] <= '9')
            cout << lltor(stoll(s)) << "\n";
        else
            cout << rtoll(s) << "\n";
    }
    
    return 0;
}