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

void maxSubArraySum(ll a[], ll size)
{
    ll max_so_far = INT_MIN, max_ending_here = 0,
        start = 0, end = 0, s = 0;
 
    for (ll i = 0; i < size; i++) {
        max_ending_here += a[i];
 
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
 
        if (max_ending_here < 0) {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    cout << max_so_far << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n; cin >> n; ll arr[n];
    
    forn(i,0,n) cin >> arr[i];

    maxSubArraySum(arr, n);

    //test:
    //5
    //-1 -2 -3 -4 -5

    //hasilnya harusnya 0
}