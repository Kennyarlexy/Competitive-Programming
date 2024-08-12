#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    //use ll when possible!
    string s;
    ll t = 0;
    while (true) {
        cin >> s;
        if (s == "#") break;
        cout << "Case " << ++t << ": ";
        if (s == "HELLO") cout << "ENGLISH";
        else if (s == "HOLA") cout << "SPANISH";
        else if (s == "HALLO") cout << "GERMAN";
        else if (s == "BONJOUR") cout << "FRENCH";
        else if (s == "CIAO") cout << "ITALIAN";
        else if (s == "ZDRAVSTVUJTE") cout << "RUSSIAN";
        else cout << "UNKNOWN";
        cout << "\n";
    }

    return 0;
}