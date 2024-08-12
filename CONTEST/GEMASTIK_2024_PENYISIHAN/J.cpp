#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ld long double
#define ii pair<int,int>
#define pll pair<ll,ll>
#define lll tuple<ll,ll,ll>
#define iii tuple<int,int,int>
#define forn(i,a,b) for (int i = a; i <= b; i++)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define dbg(v) \
cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

#define m1(x) template<class T, class... U> void x(T&& a, U&&... b)
#define m2(x) (int[]){(x forward<U>(b),0)...}
m1(out) { cout << forward<T>(a);  m2(cout << " " <<); cout << "\n"; }
m1(in) { cin >> forward<T>(a); m2(cin >>); }


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; in(n);
    int arr[n];
    int Min = INT_MAX, Max = INT_MIN;
    int mm = INT_MIN;
    forn(i,0,n-1){
        cin >> arr[i];
        Max = max(Max, arr[i]);
        Min = min(Min, arr[i]);
    }

    sort(arr,arr+n);

    forn(i,1,n-1){
        mm = max(mm, arr[i]-arr[i-1]);
    }

    out(mm);
    out(Max-Min);

    return 0;
}