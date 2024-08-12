#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

ll A[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        bool f = false;
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            if (A[i] % 3 == 1) f = true;
            sum += A[i];
        }

        if (sum % 3 == 0) cout << "0\n";
        else if (sum % 3 == 2) cout << "1\n";
        else {
            if (f) cout << "1\n";
            else cout << "2\n";
        }
    }
    
    return 0;
}