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
#include <unordered_map>
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

unordered_map<ll, ll> freq;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n; cin >> n;
	set<ll> unique;
	vector<ll> res;
	forn(i,0,n){
		ll temp; cin >> temp;
		unique.insert(temp);
		++freq[temp];
	}
	
	for(auto x: unique){
		res.pb(freq[x]);
		cout << freq[x] << " ";
	}
	
	cout << "\n";
	sort(res.begin(), res.end());
	
	for(auto x: res){
		cout << x << " ";
	}
	
	cout << "\n";
	ll sum = res[0] * (unique.size()-2);
	
	for(ll i = 1; i < res.size(); i++){
		sum += (res[i] - res[i-1]) * max((ll)0, (ll) unique.size()-i-2);
		cout << "sum += " << (res[i] - res[i-1]) * max((ll)0, (ll)unique.size()-i-2) << "\n";
	}
	
	cout << sum << "\n";
}