#include <bits/stdc++.h>
#define ll long long
using namespace std;

string C[100]; //card
ll C_int[100]; //card in integer, v
ll cnt[15];

multiset<ll> MS;

ll f(multiset<ll> _MS) {
    vector<ll> streak_len;
    while (!_MS.empty()) {
        ll len = 0;
        bool part_of_segment = false;
        bool A = _MS.find(1) != _MS.end(), K = _MS.find(13) != MS.end();
        for (ll c = 1; c <= 13; c++) {
            if (_MS.find(c) != _MS.end()) {
                part_of_segment = true;
                len++;
                _MS.erase(_MS.find(c));
            } else if (part_of_segment) break;
        }
        if (A && K) {
            for (ll c = 13; c >= 1; c--) {
                if (_MS.find(c) != _MS.end()) {
                    len++;
                    _MS.erase(_MS.find(c));
                } else break;
            }
        }
        streak_len.push_back(len);
    }

    sort(streak_len.begin(), streak_len.end(), greater<ll> ());
    
    if (streak_len[0] == 5) return 100;
    else if (streak_len[0] == 4) return 10;
    else if (streak_len.size() > 1 && streak_len[0] == 3 && streak_len[1] == 2) return 5;
    else if (streak_len[0] == 3) return 3;
    else if (streak_len.size() > 1 && streak_len[0] == 2 && streak_len[1] == 2) return 1;
    else return 0;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        cin >> C[1];
        if (C[1] == "#") break;
        cin >> C[2] >> C[3] >> C[4] >> C[5];

        fill(cnt, cnt + 15, 4);
        MS = {};

        for (ll i = 1; i <= 5; i++) {
            ll v;
            if (C[i][0] >= '2' && C[i][0] <= '9') v = C[i][0] - '0';
            else if (C[i][0] == 'A') v = 1;
            else if (C[i][0] == 'T') v = 10;
            else if (C[i][0] == 'J') v = 11;
            else if (C[i][0] == 'Q') v = 12;
            else v = 13;
            
            cnt[v]--;
            C_int[i] = v;
            MS.insert(v);
        }

        double before = f(MS) - 1;
        ll erased = -1;
        vector<ll> temp;
        for (auto& v : MS) {
            temp.push_back(v);
        }

        for (auto& v : temp) {
            double straight = 0, invite = 0, bed = 0, menage = 0, Double_dutch = 0;
            MS.erase(MS.find(v));
            for (ll c = 1; c <= 13; c++) {
                if (c == v || cnt[c] == 0) continue;
                auto _MS = MS;
                _MS.insert(c);
                ll payment = f(_MS);
                if (payment == 1) Double_dutch += cnt[c];
                else if (payment == 3) menage += cnt[c];
                else if (payment == 5) bed += cnt[c];
                else if (payment == 10) invite += cnt[c];
                else if (payment == 100) straight += cnt[c];
            }
            double after = (straight*100 + invite*10 + bed*5 + menage*3 + Double_dutch) / 47 - 2;
            if (after > before) {
                before = after;
                erased = v;
            }
            MS.insert(v);
        }

        if (erased == -1) cout << "Stay\n";
        for (ll i = 1; i <= 5; i++) {
            if (erased == C_int[i]) {
                cout << "Exchange " << C[i] << "\n";
                break;
            }
        }
    }

    return 0;
}