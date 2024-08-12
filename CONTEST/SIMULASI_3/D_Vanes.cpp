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
	ll n; cin >> n;
	
	forn(i,0,n){
	    double a,t,k; cin >> a >> t >> k;
	    
	    double luas = a*t;
	    double dim = (1+sqrt(2)) * k;
		// double dim = k * sqrt(4 + 2*sqrt(2));
		// cout << "dim = " << dim << '\n';
		ll vertical = t / dim;
		ll horizontal = a / dim;
	    
	    cout << vertical*horizontal << "\n";

		// jadinya problem nya kaya gini, ada berapa kotak dim*dim yang bisa ditaroh di kotak a*t
		
		// a/dim = 15.5
		// b/dim = 15.5
		// a/dim itu persegi yang bisa ditaroh kalau berjejer, ga bakal bisa koma kan
		
	}
}