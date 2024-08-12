#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;

pair<ll, string> A[] = {
    {100, "c"},
    {90, "xc"},
    {50, "l"},
    {40, "xl"},
    {10, "x"},
    {9, "ix"},
    {5, "v"},
    {4, "iv"},
    {1, "i"}
};

char D[] = {'i', 'v', 'x', 'l', 'c'};

ll cnt[105][300];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (ll i = 1; i <= 100; i++) {
        ll x = i;
        for (ll j = 0; j < 9; j++) {
            while (x >= A[j].f) {
                for (auto& ch : A[j].s) cnt[i][ch]++;
                x -= A[j].f;
            }
        }
    }

    for (ll i = 2; i <= 100; i++) {
        for (ll j = 0; j < 5; j++) {
            cnt[i][D[j]] += cnt[i-1][D[j]];
        }
    }
    
    ll n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        cout << n << ":";
        bool flag = false;
        for (ll j = 0; j < 5; j++) {
            if (flag) cout << ",";
            cout << " " << cnt[n][D[j]] << " " << D[j];
            flag = true;
        }
        cout << "\n";
    }
    
    return 0;
}