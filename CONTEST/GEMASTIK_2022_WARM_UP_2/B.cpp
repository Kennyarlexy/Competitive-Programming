#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

bool sieve[150];
vector<ll> prime;

void construct_sieve(bool A[], ll size) {
    A[0] = A[1] = true;
    for (ll i = 2; i <= size; i++) {
        if (A[i]) continue;
        prime.push_back(i);
        for (ll j = i*i; j <= size; j+=i) {
            A[j] = true;
        }
    }
}


ll f(ll end, ll size) {
    ll result = 0;
    for (ll i = 1; i < (1LL<<size); i++) {
        ll onBit = __builtin_popcountll(i);
        ll lcm = 1;
        ll mask = i;
        while (mask > 0) {
            ll j = __builtin_ctzll(mask);
            lcm = lcm / __gcd(lcm, prime[j]) * prime[j];
            mask ^= (1 << j);
        }
        ll k = end/lcm;
        result += (onBit & 1 ? k : -k); // mirip soal easy math, di sana cuma perlu 2^5
    }

    return result;
}

int main() {
    fast_io();
    //use ll when possible!
    ll N; cin >> N;
    construct_sieve(sieve, 130);
    for (ll i = 1; i <= N; i++) {
        ll A, B; cin >> A >> B;
        
        ll primeSize = 0;
        for (ll i = 0; i < prime.size(); i++) {
            if (prime[i] > A) break;
            primeSize++;
        }

        ll res = (B-1) - (f(B, primeSize));
        // jumlah bilangan [2, B] yang tidak bisa dibagi oleh [2, A] = total bilangan dari A sampai B - jumlah bilangan yang terbagi

        //20 / 2 = 10 bilangan yang habis dibagi 2 untuk [2, 20]
        //5 7 11 13 17 19 = (20-2+1) - 13 = 6
        //

        //20 / 3 = 6
        //3 6 9 12 15 18

        // 10 + 6 = 16

        // 20 / 6 = 3
        // 6, 12, 18

        // 10 + 6 - 3 = 13

        // consider genap bilangan, kurang
        // consider ganjil bilangan, tambah

        cout << res << "\n";
    }


    return 0;
}