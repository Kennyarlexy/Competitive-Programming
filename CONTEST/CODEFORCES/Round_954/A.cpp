#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second 
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int a, b, c; cin >> a >> b >> c;
        int mn = INT_MAX;
        for (int i = 1; i <= 10; i++) {
            mn = min(mn, abs(a-i) + abs(b-i) + abs(c-i));
        }

        cout << mn << "\n";
    }
    
    return 0;
}