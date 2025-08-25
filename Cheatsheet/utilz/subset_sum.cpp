#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

bool subset(ll A[], ll size, ll target) {
    for (ll i = 1; i < (1<<size); i++) {
        ll sum = 0;
        ll mask = i;
        while (mask > 0) {
            ll j = __builtin_ctzll(mask);
            sum += A[j];
            mask ^= (1 << j);
        }
        if (sum == target) return true;
    }
    return false;
}
