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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t; cin >> t;
	while(t--){
		ll a,b,c; cin >> a >> b >> c;

        while(c > 0){
            if(a >= b) a/=2;
            else b/=2;
            c--;
        }

        cout << max(a,b) << " " << min(a,b) << "\n";
	}
}