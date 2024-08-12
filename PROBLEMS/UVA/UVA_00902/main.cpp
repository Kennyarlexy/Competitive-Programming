#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N; string s;
    while (cin >> N >> s) {
        unordered_map<string, ll> MP; 
        MP.reserve(s.length()-N+1);
        for (ll i = 0; i+N-1 < s.length(); i++) {
            MP[s.substr(i, N)]++;
        }

        ll _max = 0; string res;
        for (auto& d : MP) {
            if (d.second > _max) {
                _max = d.second;
                res = d.first;
            }
        }
        cout << res << "\n";
    }
    
    return 0;
}