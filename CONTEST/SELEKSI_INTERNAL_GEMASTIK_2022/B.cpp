#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

vector<string> S[8];
bool cmp(string A, string B) {
    return A.substr(6) < B.substr(6);
}

int main() {
    fast_io();
    //use ll when possible!
    ll N; cin >> N;
    cin.ignore(100, '\n');
    for (ll i = 1; i <= N; i++) {
        string str;
        getline(cin, str);
        ll len = str.length();
        string hari = str.substr(0, len - 12);
        string waktu = str.substr(len - 11, 11);
        // cout << "|" << hari << "|\n";
        // cout << "|" << waktu << "|\n";
        if (hari == "Senin") {
            S[1].push_back(waktu);
        } else if (hari == "Selasa") {
            S[2].push_back(waktu);
        } else if (hari == "Rabu") {
            S[3].push_back(waktu);
        } else if (hari == "Kamis") {
            S[4].push_back(waktu);
        } else {
            S[5].push_back(waktu);
        }
    }

    for (ll i = 1; i <= 5; i++) {
        sort(S[i].begin(), S[i].end(), cmp);
    }

    ll res = 0;
    for (ll i = 1; i <= 5; i++) {
        string prev_end = "00:00";
        for (auto& data : S[i]) {
            // cout << "prev = " << prev_end << "\n";
            if (data.substr(0, 5) >= prev_end) {
                res++;
                prev_end = data.substr(6);
            }
        }
    }

    cout << res << "\n";

    return 0;
}