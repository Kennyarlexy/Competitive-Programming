#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll L[200005][2];
ll R[200005][2];

int main() {
    fast_io();
    //use ll when possible!
    string s; cin >> s;

    ll len_0 = 0; //jumlah 0 berurutan saat ini
    ll len_1 = 0; //jumlah 1 berurutan saat ini
    bool has_0 = false;
    bool has_1 = false;
    for (ll i = 0; i < s.length(); i++) {
        if (s[i] == '0') len_0++;
        else if (len_0 > 0) {
            ll l = i-len_0-1;
            if (l >= 0) R[l][0] = len_0;
            L[i][0] = len_0;
            len_0 = 0;
        }
    }

    //111
    //000

    if (s.length()-len_0-1 >= 0) R[s.length()-len_0-1][0] = len_0; // if len_0 == s.length() dia akses index -1 

    for (ll i = 0; i < s.length(); i++) {
        if (s[i] == '1') len_1++;
        else if (len_1 > 0) {
            ll l = i-len_1-1; //1110
            if (l >= 0) R[l][1] = len_1;
            L[i][1] = len_1;
            len_1 = 0;
        }
    }

    if (s.length()-len_1-1 >= 0) R[s.length()-len_1-1][1] = len_1;


    ll res = 0;
    for (ll i = 0; i < s.length(); i++) {        
        if (s[i] == '0') {
            has_0 = true;
            res = max(res, R[i][1] + L[i][1] + 1);
        } else {
            has_1 = true;
            res = max(res, R[i][0] + L[i][0] + 1);
        }
    }

    if (s.length() == 1) cout << "1\n";
    else if (!has_0 || !has_1) cout << s.length() - 1 << "\n";
    else cout << res << "\n";

    //0001111

    //R[i][j] berisi jumlah karakter beurutan yang hanya terdiri dari j di sebelah kanan i
    //L[i][j] berisi jumlah karakter berurutan yang hanya terdiri dari j di sebelah kiri i

    //di kasus di atas, L[3][0] = 3, L[3][1] = 0
                    //  R[3][0] = 0, R[3][1] = 3

    return 0;
}