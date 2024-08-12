#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll sieve[50000005];
ll A[105];

// dari buku Guide to Competitive Programming: Learning and Improving Algorithms Through Contests - Antti Laaksonen
void construct_sieve(ll A[], ll size) {
    A[0] = A[1] = true;
    for (ll i = 2; i <= size; i++) {
        if (A[i]) continue;
        sieve[i] = 1;
        for (ll j = i*i; j <= size; j+=i) {
            A[j] = true;
        }
    }
}

int main() {
    fast_io();
    //use ll when possible!

    ll N, M; cin >> N >> M;
    auto __time_1 = chrono::high_resolution_clock::now();
    construct_sieve(sieve, 50000000);
    for (ll i = 1; i <= 50000000; i++) {
        sieve[i] += sieve[i-1];
    }
    for (ll i = 1; i <= N; i++) {
        ll l; cin >> l;
        A[i] = sieve[l*1000000];
    }

    for (ll i = 2; i <= N; i++) {
        A[i] += A[i-1];
    }

    ll res = 0;
    ll start = 0;
    ll end = 0;
    for (ll i = M; i <= N; i++) {
        if (A[i] - A[i-M] > res) {
            res = A[i] - A[i-M];
            start = i-M+1;
            end = i;
        }
    }
    cout << res % 1000 << "\n";
    for (ll i = start; i <= end; i++) {
        cout << i << " ";
    }
    cout << "\n";
    auto __time_2 = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> exe_time_ms = __time_2 - __time_1;
    cout << exe_time_ms.count() << "ms\n";

    return 0;
}