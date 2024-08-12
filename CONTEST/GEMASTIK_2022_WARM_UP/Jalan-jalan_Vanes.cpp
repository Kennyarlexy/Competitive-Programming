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
	
	ll resx[(ll)1e5+4], resy[(ll)1e5+4];
	resx[1] = 1; resy[1] = 0;
	
	ll n; cin >> n;
	ll hi_x = 1, hi_y = 0;
	ll tot = 1;
	
	ll prev = 1;
	for(ll i = 2, k = 1; i <= n && tot < n; i++, k++){
	    tot += i;
	    if(k%4==0){
	        
	        hi_x += i;
	        /* ll temp_x = hi_x; ll temp_y = hi_y;
	        for(ll j = tot-1; j > 0 && j > prev; j--, k--){
	            temp_y--;
	            cout << tot << temp_x << " " << temp_y << "\n";
 	        } */
	    }
	    if(k%4==1) hi_y += i;
	    if(k%4==2) hi_x -= i;
	    if(k%4==3) hi_y -= i;
	    resx[tot] = hi_x;
	    resy[tot] = hi_y;
	    
	    prev = tot;
	    cout << tot << " " << resx[tot] << " " << resy[tot] << "\n";
	}
	
	

}