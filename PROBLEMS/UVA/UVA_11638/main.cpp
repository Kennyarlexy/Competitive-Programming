#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll cnt[10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        memset(cnt, 0, sizeof(cnt));
        ll M, S, TH[4], C, K;
        cin >> M >> S;
        for (ll i = 0; i < 4; i++) {
            cin >> TH[i];
        }
        cin >> C >> K;

        ll clock = 0;
        
        for (ll i = 1; i <= K; i++) {
            ll time, temp; cin >> time >> temp;
            ll l = max(0LL, clock-S), r = max(0LL, clock+time-S);
            for (ll j = 0; j < 4; j++) {
                if (!(C & (1LL << j))) continue; //check enable/disable

                ll on = 0;
                if ((C & (1LL << (j+4)) && temp > TH[j])) { //high trigger
                    on = r/M - l/M;
                    if (S >= clock && S <= clock + time) on++;
                } else if (!(C & (1LL << (j+4))) && temp < TH[j]) { //low trigger
                    on = r/M - l/M;
                    if (S >= clock && S <= clock + time) on++;
                }
                cnt[j] += on;
            }
            clock += time;
        }

        cout << "Case " << t << ": ";
        for (ll i = 0; i < 4; i++) {
            cout << (cnt[i] >= 1 ? "yes" : "no") << " \n"[i==3];
        }
    }
    
    return 0;
}

/*
1
5
5
5 10 15 20
15
1
5 15

1
100
0
0 1 2 3
255
1
10 1

1
10
10
10 10 10 10
255
1
11 15
*/