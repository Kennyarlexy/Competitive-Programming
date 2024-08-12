#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll cnt[10]; //cnt[i] is the number of char in i-th segment
ll seg[] = {' ', '?', 'M', '?', 'E', '?'};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        string s; cin >> s;
        memset(cnt, 0, sizeof(cnt));
        ll i = 1;
        bool OK = true;
        for (ll j = 0; j < s.length(); j++) {
            if (j > 0 && s[j] != s[j-1]) i++;

            if (i > 5 || seg[i] != s[j]) {
                OK = false;
                break;
            } else {
                cnt[i]++;
            }
        }

        if (!OK || cnt[2] != 1 || cnt[4] != 1 || cnt[1] == 0) {
            cout << "no-theorem\n";
        } else {
            if (cnt[5] - cnt[1] == cnt[3]) {
                cout << "theorem\n";
            } else {
                cout << "no-theorem\n";
            }
        }
    }
    
    return 0;
}

/*
??????
??E?M???
??EEMM???
??EM???
??EE??MM????
??E??M????
??M??E????
??M?EE????
*/