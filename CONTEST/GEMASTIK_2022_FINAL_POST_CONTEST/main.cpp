#include <bits/stdc++.h>
#define ll long long

using namespace std;

set<string> K[10];
string type[] = {" ", "X", "P", "K", "C"};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N; cin >> N;
    for (ll i = 1; i <= N; i++) {
        string a, b; cin >> a >> b;
        if (b == "NN") K[1].insert(a);
        else if (b == "VB") K[2].insert(a);
        else if (b == "RB") K[3].insert(a);
        else K[4].insert(a);
    }

    cin.ignore(1000, '\n');
    string line;
    while (getline(cin, line)) {
        stringstream SS(line);
        string word;
        string str; //structure
        bool OK = true;
        while (SS >> word && OK) {
            bool found = false;
            for (ll i = 1; i <= 4; i++) {
                if (K[i].find(word) != K[i].end()) {
                    found = true;
                    if (i == 4) {
                        if (str != "XP" && str != "XPX" && str != "XPK" && str != "XPXK") OK = false;
                        else str = "";
                    } else str += type[i];
                    break;
                }
            }
            if (!found) str += "X";
        }

        if (str != "XP" && str != "XPX" && str != "XPK" && str != "XPXK") OK = false;
        if (OK) cout << "dapat diterima\n";
        else cout << "tidak dapat diterima\n";
    }
    
    return 0;
}