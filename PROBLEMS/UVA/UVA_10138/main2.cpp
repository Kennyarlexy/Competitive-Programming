#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll P[30];
struct entry {
    string time, status;
    ll loc;
};

bool cmp(entry &A, entry &B) {
    return A.time < B.time;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        for (ll i = 0; i < 24; i++) {
            cin >> P[i];
        }

        unordered_map<string, vector<entry>> MP;
        string line;
        cin.ignore(1000, '\n');
        while (getline(cin, line)) {
            if (line.empty()) break;

            stringstream SS(line);
            string plate, time, status;
            ll loc;
            SS >> plate >> time >> status >> loc;
            MP[plate].push_back({time, status, loc});
        }

        map<string, ll> pay;
        for (auto& d : MP) {
            auto& plate = d.first;
            auto& v = d.second;
            sort(v.begin(), v.end(), cmp);

            for (ll i = 1; i < v.size(); i++) {
                if (v[i].status == "exit" && v[i-1].status == "enter") {
                    ll hh = stoll(v[i-1].time.substr(6, 2));
                    ll dist = abs(v[i].loc-v[i-1].loc);
                    pay[plate] += P[hh] * dist + 100;
                }
            }
        }

        for (auto& d : pay) {
            cout << fixed << setprecision(2) << d.first << " $" << (d.second + 200) / 100.0 << "\n";
        }
        if (t < T) cout << "\n";
    }
    
    return 0;
}

/*
1

10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
ABCD123 01:01:06:01 enter 17
765DEF 01:01:07:00 exit 95
ABCD123 01:01:08:03 exit 95
765DEF 01:01:05:59 enter 17
*/