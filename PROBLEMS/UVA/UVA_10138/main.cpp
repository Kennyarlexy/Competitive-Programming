#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll P[30];
struct entry {
    ll hh, type = 0, loc;
};
unordered_map<string, entry> MP;
map<string, ll> res;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        for (ll i = 0; i < 24; i++) {
            cin >> P[i];
        }

        MP = {}; MP.reserve(1005);
        res = {};
        string line;
        cin.ignore(1000, '\n');
        while (getline(cin, line)) {
            if (line.empty()) break;
            stringstream SS(line);
            string v, time, type; ll loc;
            SS >> v >> time >> type >> loc;

            ll hh = stoll(time.substr(6, 2));
            if (type == "enter") {
                if (MP[v].type == 2) {
                    res[v] += P[hh] * abs(loc - MP[v].loc) + 100;
                    MP[v].type = 0;
                } else {
                    MP[v] = {hh, 1, loc};
                }
            } else if (type == "exit") {
                if (MP[v].type == 1) {
                    res[v] += P[MP[v].hh] * abs(loc - MP[v].loc) + 100;
                    MP[v].type = 0;
                } else {
                    MP[v] = {hh, 2, loc};
                }
            }
        }

        for (auto& d : res) {
            cout << fixed << setprecision(2) << d.first << " $" << (d.second+200) / 100.0 << "\n";
        }
        if (t < T) cout << "\n";
    }
    
    return 0;
}

/*
2

10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
ABCD123 01:01:06:01 enter 17
765DEF 01:01:07:00 exit 95
ABCD123 01:01:08:03 exit 95
765DEF 01:01:05:59 enter 17

10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
ABCD123 01:01:06:01 enter 17
765DEF 01:01:07:00 exit 95
ABCD123 01:01:08:03 exit 95
765DEF 01:01:05:59 enter 17
*/