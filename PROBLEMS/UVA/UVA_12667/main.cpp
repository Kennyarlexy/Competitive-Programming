#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll LS[300]; //last solver
ll Time[300];
bool AC[20][300]; //have made AC submission

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, t, m; cin >> n >> t >> m;
    
    for (ll i = 1; i <= m; i++) {
        ll time, team; char prob; string verd;
        cin >> time >> team >> prob >> verd;

        if (verd == "Yes" && time >= Time[prob] && !AC[team][prob]) {
            LS[prob] = team;
            AC[team][prob] = true;
            Time[prob] = time;
        }
    }

    for (char prob = 'A'; prob < 'A'+n; prob++) {
        cout << prob << " ";
        if (LS[prob] == 0) cout << "- -\n";
        else cout << Time[prob] << " " << LS[prob] << "\n";
    }
    
    return 0;
}