#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

map<char, map<char, string>> tabel1;
map<char, map<char, string>> tabel2;

int main() {
    fast_io();
    //use ll when possible!
    tabel1['A']['A'] = "AB";
    tabel1['A']['B'] = "DC";
    tabel1['A']['C'] = "CC";
    tabel1['A']['D'] = "CB";

    tabel1['B']['A'] = "CA";
    tabel1['B']['B'] = "DA";
    tabel1['B']['C'] = "CD";
    tabel1['B']['D'] = "DD";

    tabel1['C']['A'] = "BC";
    tabel1['C']['B'] = "AA";
    tabel1['C']['C'] = "BA";
    tabel1['C']['D'] = "DB";

    tabel1['D']['A'] = "BD";
    tabel1['D']['B'] = "AD";
    tabel1['D']['C'] = "BB";
    tabel1['D']['D'] = "AC";

    
    
    tabel2['A']['A'] = "CD";
    tabel2['A']['B'] = "BB";
    tabel2['A']['C'] = "AC";
    tabel2['A']['D'] = "CC";

    tabel2['B']['A'] = "CB";
    tabel2['B']['B'] = "DB";
    tabel2['B']['C'] = "AD";
    tabel2['B']['D'] = "DD";

    tabel2['C']['A'] = "DA";
    tabel2['C']['B'] = "DC";
    tabel2['C']['C'] = "BC";
    tabel2['C']['D'] = "BD";

    tabel2['D']['A'] = "AA";
    tabel2['D']['B'] = "BA";
    tabel2['D']['C'] = "CA";
    tabel2['D']['D'] = "AB";

    string s; cin >> s;
    ll N = s.length();

    for (ll i = 0; i < N; i+=2) {
        char x = s[i], y = s[i+1];
        s[i] = tabel1[x][y][0];
        s[i+1] = tabel1[x][y][1];
    }

    for (ll i = 0; i < N; i+=2) {
        char x = s[i], y = s[i+1];
        s[i] = tabel2[x][y][0];
        s[i+1] = tabel2[x][y][1];
    }

    cout << s << "\n";

    return 0;
}