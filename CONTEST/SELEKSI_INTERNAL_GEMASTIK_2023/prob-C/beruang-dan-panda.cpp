# include <bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for (int i = a; i < b; i++)
#define fastio()            \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL); cout.tie(NULL);    \

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
//
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
//
typedef vector<string> vs;
typedef pair<string, string> pss;
typedef pair<string, ll> psl;
typedef vector<psl> vsl;
typedef vector<pss> vss;
//
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define mod 1000000007
vl pf;

void fillPrefixSum(vl arr, int n)
{   
    ll temp;
    temp = arr[0];
    pf.PB(temp);
    // Adding present element with previous element
    for (int i = 1; i < n; i++){
        temp = pf[i - 1] + arr[i];
        pf.PB(temp);
    }
}

int main(){
  fastio();
  ll t, c, n, k, p, a;
  string s, str;
  ll it = 0;
  cin >> n;
  vl arr;
  while(n--){
    cin >> a;
    arr.PB(a);
  }
  fillPrefixSum(arr, arr.size());

    
  cin >> t;
  while(t--){
    cin >> k >> p;
    if (k == 1){
        cout << fixed << setprecision(9) << double(double(pf[p - 1])/double(p-k+1)) << endl;
    }
    else{
        cout << fixed << setprecision(9) << double(double(pf[p - 1] - pf[k - 2])/double(p-k+1)) << endl;
    }
  }
  return 0;
}