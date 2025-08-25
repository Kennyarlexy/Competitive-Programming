#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll P(ll n, ll r) {
  if (n < r) return 0;
  ll res = 1;
  ll k = n - r;
  for (ll x = n; x > k; x--) {
     res *= x;
  }
  return res;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}