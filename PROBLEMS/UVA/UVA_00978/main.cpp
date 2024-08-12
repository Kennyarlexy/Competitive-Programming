#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    vector<ll> tG, tB;
    tG.reserve(100005); 
    tB.reserve(100005);
    for (ll t = 1; t <= T; t++) {
        ll N, SG, SB; cin >> N >> SG >> SB;
        multiset<ll> G, B;
        for (ll i = 1; i <= SG; i++) {
            ll p; cin >> p;
            G.insert(p);
        }

        for (ll i = 1; i <= SB; i++) {
            ll p; cin >> p;
            B.insert(p);
        }

        while (!G.empty() && !B.empty()) {
            tG.resize(1);
            tB.resize(1);
            ll K = min(N, (ll) min(G.size(), B.size()));
            for (ll i = 1; i <= K; i++) {
                auto topG = --G.end();
                auto topB = --B.end();
                tG.push_back(*topG); G.erase(topG);
                tB.push_back(*topB); B.erase(topB);
            }
            
            for (ll i = 1; i <= K; i++) {
                if (tG[i] > tB[i]) {
                    G.insert(tG[i]-tB[i]);
                } else if (tG[i] < tB[i]) {
                    B.insert(tB[i]-tG[i]);
                }
            }
        }

        if (G.empty() && B.empty()) {
            cout << "green and blue died\n";
        } else if (!B.empty()) {
            cout << "blue wins\n";
            for (auto itr = B.rbegin(); itr != B.rend(); itr++) {
                cout << *itr << "\n";
            }
        } else {
            cout << "green wins\n";
            for (auto itr = G.rbegin(); itr != G.rend(); itr++) {
                cout << *itr << "\n";
            }
        }
        
        if (t < T) cout << "\n";
    }
    
    return 0;
}