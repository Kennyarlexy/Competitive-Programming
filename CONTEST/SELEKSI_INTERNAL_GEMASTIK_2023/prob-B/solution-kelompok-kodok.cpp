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

void kelompokKodok(int n)
{
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i)
                cnt++;
 
            else
                cnt = cnt + 2;
        }
    }
    cout << cnt << endl;
}

int main(){
  fastio();
  ll t, c, n;
  string s, str;
  ll it = 0;
  cin >> t;
  while(t--){
    cin >> n;
    kelompokKodok(n);
  }
  return 0;
}