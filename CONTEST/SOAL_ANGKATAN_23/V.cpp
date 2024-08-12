#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

vector<ll> A;
bitset<100000005> sieve;

void construct_sieve(int sz) {
    sieve[0] = sieve[1] = true;
    for (int i = 2; i*i <= sz; i++) {
        if (sieve[i]) continue;

        for (int j = i*i; j <= sz; j += i) {
            sieve[j] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; ; i++) {
        ll X = i*(i+1)*(i+2);

        if (X >= 2000000000) break;
        A.push_back(X);
    }
    
    int N; cin >> N;
    ll k = 0;
    for (int i = 1; i <= N; i++) {
        ll Y; cin >> Y;
        ll x = upper_bound(A.begin(), A.end(), Y-1) - A.begin();

        k += x;
    }

    k %= 100000000;
    construct_sieve(k);
    ll ans = 0;
    for (int i = 2; i + 6 <= k; i++) {
        if (sieve[i] || sieve[i+6]) continue;
        ans++;
    }
    cout << ans << "\n";
    
    return 0;
}