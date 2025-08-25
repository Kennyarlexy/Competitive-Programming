#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    ll X = 0;
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        X += x;
    }

    ll Y = 0;
    for (int i = 1; i <= n; i++) {
        ll y; cin >> y;
        Y += y;
    }

    if (X > Y) {
        cout << "Pak Chanek\n";
    } else if (X == Y) {
        cout << "Mabar\n";
    } else {
        cout << "Pak Ganesh\n";
    }
    
    return 0;
}