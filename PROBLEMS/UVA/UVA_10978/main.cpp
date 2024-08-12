#include <bits/stdc++.h>
#define ll long long
using namespace std;

string cards[100];
bool F[100]; //flipped

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N;
    while (true) {
        cin >> N;
        if (N == 0) break;
        
        memset(F, 0, sizeof(F));
        ll j = 0;
        for (ll i = 1; i <= N; i++) {
            string s, t;
            cin >> s >> t;
            ll cnt = 0;
            while (cnt < t.length()) {
                j++;
                if (!F[j%N]) cnt++;
            }

            F[j%N] = true;
            cards[j%N] = s;
        }

        for (ll i = 1; i <= N; i++) {
            cout << cards[i%N] << " \n"[i==N];
        }
    }
    
    return 0;
}