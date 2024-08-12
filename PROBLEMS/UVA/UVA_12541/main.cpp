#include <bits/stdc++.h>
#define ll long long
using namespace std;

tuple<ll, ll, ll, string> A[105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n; cin >> n;
    for (ll i = 1; i <= n; i++) {
        string s;
        ll dd, mm, yyyy;
        cin >> s >> dd >> mm >> yyyy;
        A[i] = {yyyy, mm, dd, s};
    }

    sort(A+1, A+n+1);
    cout << get<3> (A[n]) << "\n";
    cout << get<3> (A[1]) << "\n";
    
    return 0;
}