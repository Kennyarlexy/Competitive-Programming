#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[5005];
ll B[5005];
ll n, m;
ll total(ll t) {
    ll sum = 0;
    for (ll i = 1; i <= n; i++) {
        sum += ((t-1)/(B[i] + 1) + 1)*A[i];
    }
    return sum;
}


int main() {
    fast_io();
    //use ll when possible!
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (ll i = 1; i <= n; i++) {
        cin >> B[i];
    }
    
    //kurangin t jika ternyata setelah dikurangi pun masih mencukupi
    ll t = 1e12;
    for (ll step = 1e12/2; step >= 1; step/=2) {
        while (t-step > 0 && total(t-step) >= m) t -= step;
    }

    cout << t << "\n";

    return 0;
}