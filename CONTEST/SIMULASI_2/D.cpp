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
	ll ii,jj,kk, sum = -1e11; cin >> ii >> jj >> kk;
	
	ll jjj[2], kkk[2], iii[2];
	
		jjj[0] = -1e10; kkk[0] = -1e10; iii[0] = -1e10;
		jjj[1] = 1e10; kkk[1] = 1e10; iii[1] = 1e10;
		
	
	ll maxi = -1e10, maxj = -1e10, maxk = -1e10;
	
	forn(i,0,ii){
		ll temp; cin >> temp;
		iii[0] = max(iii[0], temp);
		iii[1] = min(iii[1], temp);
	}
	
	forn(i,0,jj){
		ll temp; cin >> temp;
		jjj[0] = max(jjj[0], temp);
		jjj[1] = min(jjj[1], temp);
	}
	
	forn(i,0,kk){
		ll temp; cin >> temp;
		kkk[0] = max(kkk[0], temp);
		kkk[1] = min(kkk[1], temp);
	}
	
	forn(i,0,2){
		forn(j,0,2){
			forn(k,0,2){
				
				ll res = iii[i] * jjj[j] * kkk[k];
				sum = max(sum, res);
			}
		}
	}
	
	cout << sum << "\n";
    return 0;
}