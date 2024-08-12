#include <bits/stdc++.h>
#define ll long long
using namespace std;

void construct_sieve(bool sieve[], ll size) {
    sieve[0] = sieve[1] = true;
    for (ll i = 2; i <= size; i++) {
        if (sieve[i]) continue;
        for (ll j = i*i; j <= size; j+=i) {
            sieve[j] = true;
        }
    }
}
