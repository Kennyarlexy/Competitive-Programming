#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

bool sieve[105];

void make_sieve(int n) {
    sieve[0] = sieve[1] = true;
    for (int i = 2; i*i <= n; i++) {
        if (sieve[i]) continue;
        for (int j = i*i; j <= n; j += i) {
            sieve[j] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    int mn = INT_MAX, mx = INT_MIN, X = 0;
    make_sieve(100);
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        int y = x;
        if (x > 1) {
            if (x % 2 == 1) y += 1;
            else y += 2;
        }

        if (!sieve[x]) y += 3;
        if (y > 0) mn = min(mn, y);
        mx = max(mx, y);
        X += y;
    }
    if (mn == INT_MAX) mn = mx;
    cout << mn << "\n" << mx << "\n" << X << "\n";

    // for (int i = 1; i <= 100; i++) {
    //     cout << setw(3) << i << " -> " << (sieve[i] ? "not prime" : "prime") << "\n";
    // }

    return 0;
}