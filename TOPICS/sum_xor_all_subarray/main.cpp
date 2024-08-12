#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    ll sum = 0;
    for (int i = 0; i < 20; i++) {
        ll x = (1 << i);
        ll odd = 0;
        for (int j = 1; j <= n; j++) {
            if (A[j] & x) odd = j - odd;
            sum += (x * odd);
        }
    }

    cout << sum << "\n";
    
    return 0;
}