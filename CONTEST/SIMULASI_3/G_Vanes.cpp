#include <iostream>
#include <algorithm> // sort()
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <sstream>
#include <cstring> // memset() toupper()
#include <cmath> // sqrt(), abs()
#include <numeric> // lcm(), gcd()
#include <iomanip> // setprecision()
#include <stdlib.h> // use labs for ll/ull, not abs
#include <climits> // LLONG_MAX, ULLONG_MAX, INT_MAX

#define ll long long
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define ld long double
#define ull unsigned long long
#define forn(i, k, n) for (int i = k; i < int(n); i++)

using namespace std;

const ll mod = 1e9 + 7;
const ull INF = LLONG_MAX;


ll modexp(ll X, ll exp, ll mod = 1000000007) {
    if (exp == 0) return 1;
    
    ll temp = modexp(X, exp/2, mod);
    ll res = (temp * temp) % mod;
    if (exp % 2 == 1) res = (res * X) % mod;

    return res;
}

ll phi(ll n)
{
    // Initialize result as n
    ll result = n;
  
    // Consider all prime factors of n
    // and subtract their multiples
    // from result
    for(ll p = 2; p * p <= n; ++p)
    {
         
        // Check if p is a prime factor.
        if (n % p == 0)
        {
             
            // If yes, then update n and result
            while (n % p == 0)
                n /= p;
                 
            result -= result / p;
        }
    }
  
    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result -= result / n;
         
    return result;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	queue<ll> hi;
	ll n; cin >> n;
	hi.push((ll) 1e9+7);
	ll res = mod;
	
	for(ll i = 1; i < n; i++){
	    res = phi(res);
	    hi.push(res);
    }
    
    ll hasil = 0;
    
    for(ll i = 1; i <= n; i++){
        hasil = modexp(i, hasil % hi.front());
        hi.pop();
    }
    
    cout << hasil << "\n";

    // 5^4^3^2^1 mod n
    // 5^(4^3^2^1 % phi(n)) mod n
    // 5^(4^(3^2^1 % phi(phi(n)) % phi(n)) mod n

    // so, hi berisi phi phi phi phi phi phi n sampe depth n-1
    // hi = {m, phi(m), phi(phi(m)), .......}
}