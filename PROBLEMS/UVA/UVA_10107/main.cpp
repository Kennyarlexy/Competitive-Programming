#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[10005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a;
    ll i = 0;
    while (cin >> a) {
        A[i++] = a;
        if (i % 2 == 1) {
            ll m = (i-1)/2;
            nth_element(A, A+m, A+i);
            cout << A[m] << "\n";
        } else {
            ll m = (i-1)/2;
            nth_element(A, A+m, A+i);
            ll l = A[m];
            nth_element(A, A+m+1, A+i);
            ll r = A[m+1];
            cout << (l+r)/2 << "\n";
        }
    }
    
    return 0;
}