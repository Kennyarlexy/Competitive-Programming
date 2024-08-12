#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    //use ll when possible!
    ll N, A, B; cin >> N >> A >> B;
    ll lcm = A*B / __gcd(A, B);
    ll len_per_lcm = (lcm / A) + (lcm / B) - 1;
    ll lcm_cnt = N / len_per_lcm;
    ll cur = lcm_cnt * lcm;
    ll n = len_per_lcm * lcm_cnt;

    ll next_A = cur + A;
    ll next_B = cur + B;
    while (n < N) {
        if (next_A < next_B) {
            cur = next_A;
            next_A += A;
        } else if (next_B < next_A) {
            cur = next_B;
            next_B += B;
        } else {
            cur = next_A;
            next_A += A;
            next_B += B;
        }
        n++;
    }

    cout << cur << "\n";

    return 0;
}