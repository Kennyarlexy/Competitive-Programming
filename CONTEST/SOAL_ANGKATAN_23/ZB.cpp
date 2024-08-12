#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

bitset<200'000'015> sieve;
vector<int> prime(11'078'999);
ll A[105];

void construct_sieve(ll sz) {
    sieve[0] = sieve[1] = true;
    for (ll i = 2; i*i <= sz; i++) {
        if (sieve[i]) continue;
        for (ll j = i*i; j <= sz; j+=i) {
            sieve[j] = true;
        }
    }
}

ll f(ll x) {
    ll y = 0;
    for (auto p : prime) {
        if (x-p < 0) break;

        if (!sieve[(x-p)/2]) y++;
    }

    return y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    construct_sieve(200'000'005);
    for (int i = 2; i <= N; i++) {
        if (!sieve[i]) prime.push_back(i);
    }

    map<ll, ll> MP; // order
    for (ll i = 2, j = 0; i+2 <= N; i++) {
        ll A = i;
        ll B = i+2;
        if (sieve[A] || sieve[B]) continue;

        ll X = A + B;
        ll Y = A*B - (A+B);
        j++;
        if (MP.count(X) == 0) MP[X] = j;
        if (MP.count(Y) == 0) MP[Y] = j;
    }
    
    ll n, K; cin >> n >> K;
    
    ll mn = LLONG_MAX, mx = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        
        if (MP.count(A[i])) {
            A[i] = MP[A[i]];
        } else {
            if (A[i] % 2 == 0) A[i]++;
            A[i] = f(A[i]);
        }
        mn = min(mn, A[i]);
        mx = max(mx, A[i]);
    }

    ll a = mn + K;
    ll b = mx - K;
    if (a < b) cout << "-1\n";
    else cout << a << "\n";
    
    return 0;
}

