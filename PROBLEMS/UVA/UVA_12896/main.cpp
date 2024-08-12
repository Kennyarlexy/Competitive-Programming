#include <bits/stdc++.h>
#define ll long long
using namespace std;

string A[10] = {" ", "\".,?", "cab", "fde", "igh", "ljk", "omn", "spqr", "vtu", "zwxy"};
ll key[105];
ll f[105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll N; cin >> N;
        for (ll i = 1; i <= N; i++) {
            cin >> key[i];            
        }
        for (ll i = 1; i <= N; i++) {
            cin >> f[i];
        }

        for (ll i = 1; i <= N; i++) {
            ll l = A[key[i]].length();
            cout << A[key[i]][f[i]%l];
        }
        cout << "\n";
    }
    
    return 0;
}