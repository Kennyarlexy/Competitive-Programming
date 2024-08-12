#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

map<string, ll> MP;

int main() {
    fast_io();
    //use ll when possible!
    ll n; cin >> n;
    set<string> best3;
    ll sum = 0;
    for (ll i = 1; i <= n; i++) {
        string t; cin >> t;
        MP[t]++;
        if (best3.find(t) != best3.end()) {
            sum++;
        } else if (best3.size() < 3) {
            sum += MP[t];
            best3.insert(t);
        } else {
            bool outdated = false;
            string outdated_crystal;
            for (auto& best : best3) {
                if (MP[best] < MP[t]) {
                    outdated_crystal = best;
                    outdated = true;
                }
            }
            if (outdated) {
                sum += (MP[t] - MP[outdated_crystal]);
                best3.erase(outdated_crystal);
                best3.insert(t);
            }
        }

        cout << MP.size() << " " << sum << "\n";
    }


    return 0;
}