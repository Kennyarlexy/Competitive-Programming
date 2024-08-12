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
	ll n,m; cin >> n >> m; ll arr[n][m];
	ll dpbhor[n][m],dpfhor[n][m], dpfver[n][m], dpbver[n][m];
	ll maxx = -1e16;
	forn(i,0,n){
	    forn(j,0,m){
	        cin >> arr[i][j];
	    }
	}
	
	forn(i,0,n){
	    
	    dpfhor[i][0] = arr[i][0];
	    forn(j,1,m){
	        dpfhor[i][j] = dpfhor[i][j-1] + arr[i][j];
	    }
	    
	    dpbhor[i][m-1] = arr[i][m-1];
	    for(ll j = max((ll) 0, m-2); j >= 0; j--){
	        dpbhor[i][j] = dpbhor[i][j+1] + arr[i][j];
	    }
	}
	
	forn(i,0,m){
	    
	    dpfver[0][i] = arr[0][i];
	    forn(j,1,n){
	        dpfver[j][i] = dpfver[j-1][i] + arr[j][i];
	    }
	    
	    dpbver[n-1][i] = arr[n-1][i];
	    for(ll j = max((ll) 0, n-2); j >= 0; j--){
	        dpbver[j][i] = dpbver[j+1][i] + arr[j][i];
	    }
	}
	
	forn(i,0,n){
	    forn(j,0,m){
	        ll sum = 0;
	        if(i == 0 && n != 1){
	            sum += dpbver[1][j];
	        }
	
	        if(i == n-1 && n != 1){
	            sum += dpfver[n-2][j];
	        }
	        
	        if(i != 0 && i != n-1 && n != 1){
	            sum += dpfver[i-1][j] + dpbver[i+1][j];
	        }
	        
            if(j == 0 && m != 1){
	            sum += dpbhor[i][j+1];
	        }
	
	        if(j == m-1 && m != 1){
	            sum += dpfhor[i][j-1];
	        }
	        
	        if(j != 0 && j != m-1 && m != 1){
	            sum += dpfhor[i][j-1] + dpbhor[i][j+1];
	        }
	        
	        maxx = max(sum, maxx);
	    }
	}
	
	cout << maxx << "\n";
}