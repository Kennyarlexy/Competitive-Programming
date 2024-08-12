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

bool visited[300000] = {false};
vector<ll> to;
ll k = 0;

void dfs(ll x){
	// cout << "visiting " << x << "\n";
	if(visited[x]) return;
	visited[x] = true;
	++k;
	
	dfs(to[x-1]);
}
int main(){
	ll n,ii; cin >> n >> ii;
	
	forn(i,0,n){
		ll temp; cin >> temp;
		to.pb(temp);
	}
	
	dfs(ii);
	
	if(k == n) cout << "YA\n";
	else cout << "TIDAK\n";
	
    return 0;
}