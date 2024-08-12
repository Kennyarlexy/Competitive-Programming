#include <bits/stdc++.h>
#define ll long long
using namespace std;

string ABO[] = {"A", "B", "O"};
string Rh[] = {"+", "-"};
string type[] = {"A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"};
vector<string> all;
set<tuple<string, string, string>> possible;
map<string, string> MP;

string f(string s) {
    string com = s.substr(0, 2);
    string com_rh = s.substr(2);
    string type, rh;
    if (com == "AA" || com == "AO" || com == "OA") {
        type = "A";
    } else if (com == "BB" || com == "BO" || com == "OB") {
        type = "B";
    } else if (com == "AB" || com == "BA") {
        type = "AB";
    } else {
        type = "O";
    }

    if (com_rh == "++" || com_rh == "+-" || com_rh == "-+") {
        rh = "+";
    } else if (com_rh == "--") {
        rh = "-";
    }

    return type + rh;
}

void print(vector<string> &v) {
    if (v.size() == 0) cout << "IMPOSSIBLE";
    else if (v.size() == 1) cout << v[0];
    else {
        cout << "{";
        bool flag = false;
        for (auto& data : v) {
            if (flag) cout << ", ";
            cout << data;
            flag = true;
        }
        cout << "}";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (ll i = 0; i < 3; i++) {
        for (ll j = 0; j < 3; j++) {
            for (ll k = 0; k < 2; k++) {
                for (ll l = 0; l < 2; l++) {
                    all.push_back(ABO[i] + ABO[j] + Rh[k] + Rh[l]);
                }
            }
        }
    }

    for (auto& s : all) {
        MP[s] = f(s);
    }

    for (ll i = 0; i < all.size(); i++) 
    for (ll j = 0; j < all.size(); j++) 
    for (ll k = 0; k < 2; k++) 
    for (ll l = 0; l < 2; l++) 
    for (ll m = 2; m < 4; m++) 
    for (ll n = 2; n < 4; n++) {
        string child;
        child += all[i][k];
        child += all[j][l];
        child += all[i][m];
        child += all[j][n];
        possible.insert({MP[all[i]], MP[all[j]], MP[child]});
    }
    
    ll t = 0;
    string p1, p2, ch;
    while (true) {
        cin >> p1 >> p2 >> ch;
        if (p1 == "E" && p2 == "N" && ch == "D") break;

        vector<string> temp;
        cout << "Case " << ++t << ": ";        
        if (p1 == "?") {
            for (ll i = 0; i < 8; i++) {
                if (possible.find({type[i], p2, ch}) != possible.end()) {
                    temp.push_back(type[i]);
                }
            }
            print(temp);
            cout << " " << p2 << " " << ch << "\n";
        } else if (p2 == "?") {
            cout << p1 << " ";
            for (ll i = 0; i < 8; i++) {
                if (possible.find({p1, type[i], ch}) != possible.end()) {
                    temp.push_back(type[i]);
                }
            }
            print(temp);
            cout << " " << ch << "\n";
        } else {
            cout << p1 << " " << p2 << " ";
            for (ll i = 0; i < 8; i++) {
                if (possible.find({p1, p2, type[i]}) != possible.end()) {
                    temp.push_back(type[i]);
                }
            }
            print(temp);
            cout << "\n";
        }
    }
    
    return 0;
}

/*
O+ O- ?
O+ ? O-
AB- AB+ ?
AB+ ? O+
E N D
*/