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

struct Data{
    string asal, tujuan;
    ll jarak;
};

bool comp(Data a, Data b){
    return (a.jarak > b.jarak);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n; cin >> n;
	vector<Data> hii;
	forn(i,0,n){
	    string as, tu; ll a1,a2,a3,b1,b2,b3; cin >> as >> a1 >> a2 >> a3 >> tu >> b1 >> b2 >> b3;
	    
	    double dis = sqrt(abs(a1-b1) * abs(a1-b1) + abs(a2-b2) * abs(a2-b2));
	    
	    hii.pb({as,tu,(ll)dis});
	    
	}
	
	sort(hii.begin(), hii.end(), comp);
	
	for(auto x: hii){
	    cout << x.asal << " " << x.tujuan << " " << x.jarak << "\n";
	}
}