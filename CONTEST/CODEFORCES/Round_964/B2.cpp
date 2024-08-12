#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll a1, a2, b1, b2;

bool f() {
    int x = (a1 > b1) + (a2 > b2);
    int y = (a1 < b1) + (a2 < b2);
    return x > y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> a1 >> a2 >> b1 >> b2;
        int ans = f();
        swap(b1, b2);
        ans += f();
        swap(b1, b2);

        swap(a1, a2);
        ans += f();
        swap(b1, b2);
        ans += f();
        cout << ans << "\n";

    }
    
    return 0; 
}